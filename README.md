# Navilos
Embedded OS Development Project



# Command List

3.4: make exe file by linker (code 3.4)
> $ arm-none-eabi-ld -n -T ./navilos.ld -nostdlib -o navilos.axf boot/Entry.o

> $ arm-none-eabi-objdump -D navilos.axf


code 3.5: execute axf file by QEMU
- exe by QEMU 
> $ qemu-system-arm -M realview-pb-a8 -kernel navilos.axf -S -gdb tcp::1234,ipv4
<br>
> explanation: -M : option to select the machine we choose realview-pb-a8, 
> -kernel is for assigning ELF, 
> -S is for when QEMU run, instantly suspend the program -> 
<br>
