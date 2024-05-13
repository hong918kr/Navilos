# Navilos
Embedded OS Development Project 
- Fundamental Structure of ARM Based Firmware/RTOS


# Note
code 3.2: Compile Entry.S and binary dump command
- $ arm-none-eabi-as -march=armv7-a -mcpu=cortex-a8 -o Entry.o ./Entry.S
- $ arm-none-eabi-objcopy -O binary Entry.o Entry.bin
- $ hexdump Entry.bin


code 3.2: Compile Entry.S and binary dump command