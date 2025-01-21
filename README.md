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
- ch 7 - Timer
  - $   wget https://github.com/navilera/Navilos/archive/fcd6a32a91d5d4053fbcd7b7e8689f77c74c2989.zip
- Ch 8 - Task
  - $   wget https://github.com/navilera/Navilos/archive/e9b04bb60da9b282ec2761e5036a1aa9a6d2be68.zip
- Ch 9 - Scheduler
  - $   wget https://github.com/navilera/Navilos/archive/f02ff6b92d2a356f85c76a60a12ef6ea73fdbd81.zip
- Ch 10 - Context Switching
  - $   wget https://github.com/navilera/Navilos/archive/273b96189c6adf8f402f02f9f5ee103589492256.zip

- Ch 11 - Event
  - 11.1, 11.2 $   wget https://github.com/navilera/Navilos/archive/df3716b9ca32fa0bd6635436d48f7f814948be0d.zip
  - 11.3, 11.4 $   wget https://github.com/navilera/Navilos/archive/92d0358cc93e88c0fc61efac72296b1386611b1e.zip
- Ch 12 - Messaging
  - $   wget https://github.com/navilera/Navilos/archive/157d1dabd465e69c537d10b235512823ee277a88.zip
- Ch 13 - Syncronization
  - 13.1 (Semaphore)  $   wget https://github.com/navilera/Navilos/archive/49dcd06dabad43674c2a2df22c6b567f4777240a.zip
  - 13.2 (Mutex)      $   wget https://github.com/navilera/Navilos/archive/f680418b26e56ee9a5c6c98576ed79795c7d344b.zip

