################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/System\ Parameters/System_Parameters.c 

OBJS += \
./Core/System\ Parameters/System_Parameters.o 

C_DEPS += \
./Core/System\ Parameters/System_Parameters.d 


# Each subdirectory must supply rules for building sources it contributes
Core/System\ Parameters/System_Parameters.o: ../Core/System\ Parameters/System_Parameters.c Core/System\ Parameters/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Core/System Parameters/System_Parameters.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-System-20-Parameters

clean-Core-2f-System-20-Parameters:
	-$(RM) ./Core/System\ Parameters/System_Parameters.cyclo ./Core/System\ Parameters/System_Parameters.d ./Core/System\ Parameters/System_Parameters.o ./Core/System\ Parameters/System_Parameters.su

.PHONY: clean-Core-2f-System-20-Parameters

