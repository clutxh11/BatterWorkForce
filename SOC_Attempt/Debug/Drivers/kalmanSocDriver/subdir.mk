################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/kalmanSocDriver/BatterySOCEstimation.c \
../Drivers/kalmanSocDriver/BatterySOCEstimation_data.c 

OBJS += \
./Drivers/kalmanSocDriver/BatterySOCEstimation.o \
./Drivers/kalmanSocDriver/BatterySOCEstimation_data.o 

C_DEPS += \
./Drivers/kalmanSocDriver/BatterySOCEstimation.d \
./Drivers/kalmanSocDriver/BatterySOCEstimation_data.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/kalmanSocDriver/%.o Drivers/kalmanSocDriver/%.su: ../Drivers/kalmanSocDriver/%.c Drivers/kalmanSocDriver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/samuelmpoloka/Documents/Side Project/BatterWorkForce/SOC_Attempt/Drivers/kalmanSocDriver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-kalmanSocDriver

clean-Drivers-2f-kalmanSocDriver:
	-$(RM) ./Drivers/kalmanSocDriver/BatterySOCEstimation.d ./Drivers/kalmanSocDriver/BatterySOCEstimation.o ./Drivers/kalmanSocDriver/BatterySOCEstimation.su ./Drivers/kalmanSocDriver/BatterySOCEstimation_data.d ./Drivers/kalmanSocDriver/BatterySOCEstimation_data.o ./Drivers/kalmanSocDriver/BatterySOCEstimation_data.su

.PHONY: clean-Drivers-2f-kalmanSocDriver

