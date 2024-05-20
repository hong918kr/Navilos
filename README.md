# Navilos
Embedded OS Development Project 
- Fundamental Structure of ARM Based Firmware/RTOS


# Note
code 3.2: Compile Entry.S and binary dump command
- $ arm-none-eabi-as -march=armv7-a -mcpu=cortex-a8 -o Entry.o ./Entry.S
- $ arm-none-eabi-objcopy -O binary Entry.o Entry.bin
- $ hexdump Entry.bin

### hexdump
- hexdump -C : -C will show the ASCI with octal , 1 byte representing
-b: one byte octal display
-d: two byte decimal display


## code 3.2: Compile Entry.S and binary dump command

## code 3.3: initial linker script

## code 3.4: Make exe file by linker
- $ arm-none-eabi-ld -n -T ./navilos.ld -nostdlib -o navilos.axf boot/Entry.o
- $ arm-none-eabi-objdump -D navilos.axf
  - -D stnads for disassemble


Once we try to execute by ./navilos.axf, comming out the exec format error. Reason being from here on linux kernel, since we'ven't had linux library as well as section was not adequte to run via linux

To solve this: run on the ARM board or run via QEMU
## code 3.5: Run by Qemu
- $ qemu-system-arm -M realview-pb-a8 -kernel navilos.axf -S -gdb tcp::1234,ipv4
  - `-M` : designate the machine (realview-pb-a8)
  - `-kernel` : set kernel option as elf file
  - `-S`: once QEMU exe, pause the application
  - `-gdb tcp::1234,ipv4`: connect gdb 


## code 3.6: Connect gdb and QEMU
- $ arm-none-eabi-gdb
- $ (gdb) target remote:1234
- `Note`: if you have a trouble to use gdb, 
  - when you've done: sudo apt install arm-none-eabi-gdb
  - you do: `ln -s /usr/bin/gdb-multiarch /usr/bin/arm-none-eabi-gdb` to enable with arm-none-eabi-gdb on user side

## code 3.7: Build Automation


# gdb tip:
- (gdb) step (s) : run one line of the source code
- (gdb) info register (i r) :  see the current register status
- (gdb) list: check if read debug symbol
- (gdb) target remote:1234 : connect qemu via debugging socket by target cmd
- (gdb) file build/navilos.axf : read debugging symbol in elf file by file cmd


## code 4.1: Exception Vector Table initial code Entry.S



## code 4.5: Modify Entry.S to setup reset handler with stack build
```asm
MRS r0, cpsr
BIC r1, r0, #0x1F
ORR r1, r1, #ARM_MODE_BIT_SVC
MSR cpsr, r1
LDR sp, =SVC_STACK_TOP
```


- MRS: Move to ARM register from system coprocessor register (Move d)
- BIC: bit clear
- ORR: Logical ORR
- MSR: ARM register to system coprocessor register
- LDR: Load

In case, you got warning: cc1: warning: switch '-mcpu=cortex-a8' conflicts with '-march=armv7-a' switch
-> https://bugs.launchpad.net/gcc-linaro/+bug/662720
