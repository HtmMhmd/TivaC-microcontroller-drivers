/*
 *   hal_gpio.c
 *
 *    Created on: Feb 5, 2024
 *      Author: LENOVO
 */
#include "hal_gpio.h"


Std_ReturnType gpio_pin_direction_intialize(port_index_t port, port_enable_t port_enable, direction_t direction, uint8_t pins){
    Std_ReturnType ret = E_OK;
        if(NULL == port || NULL == port_enable){
            ret = E_NOT_OK;
        }
        else{
            ret = gpio_port_enable(port, port_enable);
            if(direction){ // INPUT
                GPIOPinTypeGPIOInput(port,
                                     pins);
            }
            else{       //OUTPUT
                GPIOPinTypeGPIOOutput(port,
                                      pins);
            }
        }
        return ret;
}

Std_ReturnType gpio_pin_write_logic(port_index_t port, uint8_t pins, uint8_t logic){
    Std_ReturnType ret = E_OK;
    if(NULL == port){
        ret = E_NOT_OK;
    }
    else{
        GPIOPinWrite(port, pins, logic);
        }
    return ret;
}

Std_ReturnType gpio_pin_read_logic(port_index_t port, uint8_t pins, uint32_t * save_logic){
    Std_ReturnType ret = E_OK;
    if(NULL == port){
        ret = E_NOT_OK;
    }
    else{
        *save_logic = GPIOPinRead(port, pins);
        }
    return ret;
}


/*'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/

Std_ReturnType gpio_port_enable(port_index_t port, port_enable_t port_enable){
    Std_ReturnType ret = E_OK;
    if(NULL == port || NULL == port_enable ){
            ret = E_NOT_OK;
        }
        else{
            SysCtlPeripheralEnable(port_enable);
            while(!SysCtlPeripheralReady(port_enable));
        }
        return ret;
}
Std_ReturnType gpio_port_direction_intialize(port_index_t port, port_enable_t port_enable , direction_t direction){
    Std_ReturnType ret = E_OK;
        if(NULL == port || NULL == port_enable ){
            ret = E_NOT_OK;
        }
        else{
            ret = gpio_port_enable(port, port_enable);
            gpio_pin_direction_intialize(port, port_enable, direction, 0xFF);
        }
        return ret;
}


Std_ReturnType gpio_port_write_logic(port_index_t port, uint8_t logic){
    Std_ReturnType ret = E_OK;
    if(NULL == port ){
        ret = E_NOT_OK;
    }
    else{
        gpio_pin_write_logic(port, 0xFF, logic);
    }
    return ret;
    }

Std_ReturnType gpio_port_read_logic(port_index_t port, uint32_t *save_logic){
    Std_ReturnType ret = E_OK;
            if(NULL == port ){
                ret = E_NOT_OK;
            }
            else{
                *save_logic = gpio_pin_read_logic(port, 0xFF, save_logic);
            }
            return ret;
    }
