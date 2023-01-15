CC= arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s 
INCS= -I .
LIBS=
SRC = $(wildcard *.c)      #collect all source of file.c
OBJ = $(SRC:.c=.o)       #collect and change all source of file.c to file.o
Asm = $(wildcard *.s)    #collect all source of file.s
AsmOBJ = $(Asm:.s=.o)    #collect and change all source of file.s to file.o
Project_name=learn-in-depth

all: $(Project_name).bin
	@echo "-------make is build----------"

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 2> log
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@  2>lag

$(Project_name).elf: $(OBJ) $(AsmOBJ)
	$(CC)ld.exe -T linker-script.ld $(LIBS) $(OBJ)  $(AsmOBJ) -o $@ -Map=Mapfile.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin
