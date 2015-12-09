################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
usb_schelkun.lss \

FLASH_IMAGE += \
usb_schelkun.hex \

EEPROM_IMAGE += \
usb_schelkun.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: usb_schelkun.elf secondary-outputs

# Tool invocations
usb_schelkun.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,usb_schelkun.map -mmcu=attiny13 -o "usb_schelkun.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

usb_schelkun.lss: usb_schelkun.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S usb_schelkun.elf  >"usb_schelkun.lss"
	@echo 'Finished building: $@'
	@echo ' '

usb_schelkun.hex: usb_schelkun.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex usb_schelkun.elf  "usb_schelkun.hex"
	@echo 'Finished building: $@'
	@echo ' '

usb_schelkun.eep: usb_schelkun.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex usb_schelkun.elf  "usb_schelkun.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: usb_schelkun.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=attiny13 usb_schelkun.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) usb_schelkun.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
