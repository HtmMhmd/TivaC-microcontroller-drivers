# TivaC 

## Table of Contents
- [Description](#description)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Examples](#examples)
- [Documentation](#documentation)

## Description
This project provides a set of functions for controlling GPIO pins on a TivaC microcontroller using TivaWare Drivers.

## Usage
1. Include the necessary header file: `#include "hal_gpio.h"`
2. Use the provided functions to control GPIO pins.

## Dependencies
- Tiva C microcontroller drivers

## Examples
```c
// Initialize a GPIO pin as an input
gpio_pin_direction_intialize(GPIO_PORT_P1, GPIO_PORT_ENABLE_P1, INPUT, PIN_0);

// Write logic to a GPIO pin
gpio_pin_write_logic(GPIO_PORT_P1, PIN_0, HIGH);

// Read logic from a GPIO pin
uint32_t logic;
gpio_pin_read_logic(GPIO_PORT_P1, PIN_0, &logic);
```

# Documentation 
## MCAL Layer
### GPIO
gpio_pin_direction_intialize

    This function initializes the direction of the specified GPIO pins.

    Parameters:

        port: The port index of the GPIO pins.
        port_enable: The enable status of the GPIO port.
        direction: The direction of the GPIO pins (INPUT or OUTPUT).
        pins: The specific pins to be initialized.
    Returns:

        E_OK: The function executed successfully.
        E_NOT_OK: The function failed to execute.

gpio_pin_write_logic

    This function writes a logic value to the specified GPIO pins.

    Parameters:

        port: The port index of the GPIO pins.
        pins: The specific pins to write to.
        logic: The logic value to write (0 or 1).
    Returns:

        E_OK: The function executed successfully.
        E_NOT_OK: The function failed to execute.

gpio_pin_read_logic

    This function reads the logic value of the specified GPIO pins.

    Parameters:

        port: The port index of the GPIO pins.
        pins: The specific pins to read from.
        save_logic: A pointer to a variable where the read logic value will be stored.
    Returns:

        E_OK: The function executed successfully.
        E_NOT_OK: The function failed to execute.

gpio_port_enable

    This function enables the specified GPIO port.

    Parameters:

        port: The port index of the GPIO port.
        port_enable: The enable status of the GPIO port.
    Returns:

        E_OK: The function executed successfully.
        E_NOT_OK: The function failed to execute.

gpio_port_direction_intialize

    This function initializes the direction of all the GPIO pins in the specified port.

    Parameters:

        port: The port index of the GPIO port.
        port_enable: The enable status of the GPIO port.
        direction: The direction of the GPIO pins (INPUT or OUTPUT).
    Returns:

        E_OK: The function executed successfully.
        E_NOT_OK: The function failed to execute.

gpio_port_write_logic

    This function writes a logic value to all the GPIO pins in the specified port.

    Parameters:

        port: The port index of the GPIO port.
        logic: The logic value to write (0 or 1).
    Returns:

        E_OK: The function executed successfully.
        E_NOT_OK: The function failed to execute.

gpio_port_read_logic

    This function reads the logic value of all the GPIO pins in the specified port.

    Parameters:

        port: The port index of the GPIO port.
        save_logic: A pointer to a variable where the read logic value will be stored.
    Returns:

        E_OK: The function executed successfully.
        E_NOT_OK: The function failed to execute.


