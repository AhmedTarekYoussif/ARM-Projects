################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_program.c \
../Src/LCD_prg.c \
../Src/PB_prg.c \
../Src/RCC_program.c \
../Src/RTOS_main.c \
../Src/RTOS_program.c \
../Src/SSD_prg.c \
../Src/STK_prog.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/DIO_program.o \
./Src/LCD_prg.o \
./Src/PB_prg.o \
./Src/RCC_program.o \
./Src/RTOS_main.o \
./Src/RTOS_program.o \
./Src/SSD_prg.o \
./Src/STK_prog.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/DIO_program.d \
./Src/LCD_prg.d \
./Src/PB_prg.d \
./Src/RCC_program.d \
./Src/RTOS_main.d \
./Src/RTOS_program.d \
./Src/SSD_prg.d \
./Src/STK_prog.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DIO_program.d ./Src/DIO_program.o ./Src/DIO_program.su ./Src/LCD_prg.d ./Src/LCD_prg.o ./Src/LCD_prg.su ./Src/PB_prg.d ./Src/PB_prg.o ./Src/PB_prg.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/RTOS_main.d ./Src/RTOS_main.o ./Src/RTOS_main.su ./Src/RTOS_program.d ./Src/RTOS_program.o ./Src/RTOS_program.su ./Src/SSD_prg.d ./Src/SSD_prg.o ./Src/SSD_prg.su ./Src/STK_prog.d ./Src/STK_prog.o ./Src/STK_prog.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

