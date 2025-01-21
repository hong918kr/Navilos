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
> -gdb tcp::1234,ipv4 is for connecting to gdb, assign socket port
<br>
> $ arm-none-eabi-gdb : execute gdb
> (gdb) target remote:1234
> (gdb) x/4x 0


when compile, add -g : to add debugging symbol


code 4.3:
$make clean
$make all
$make debug
$make gdb
(gdb) target remote:1234
(gdb) file build/navilos.axf -> y
(gdb) list (check if file reads debugging symbol)
(gdb) info register (i r)
(gdb) step (s)


- code download link: 
  - $   wget https://github.com/navilera/Navilos/archive/fcd6a32a91d5d4053fbcd7b7e8689f77c74c2989.zip
- Ch 8 - Task
  - $   wget https://github.com/navilera/Navilos/archive/e9b04bb60da9b282ec2761e5036a1aa9a6d2be68.zip
