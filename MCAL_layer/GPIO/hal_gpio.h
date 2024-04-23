/*
 * hal_gpio.h
 *
 *  Created on: Feb 5, 2024
 *      Author: LENOVO
 */
/*    includes   */
#include "stdint.h"

#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"


#ifndef MCAL_LAYER_GPIO_HAL_GPIO_H_
#define MCAL_LAYER_GPIO_HAL_GPIO_H_

/*   std return*/

typedef uint8_t Std_ReturnType;

#define E_OK         (Std_ReturnType)0x01
#define E_NOT_OK     (Std_ReturnType)0x00

/*  NULL */
#define NULL 0

/*  Macro Dec  */

typedef enum{
    OUTPUT  = 0,
    INPUT   = 1

}direction_t;

typedef enum{
            EN_PORTA = SYSCTL_PERIPH_GPIOA,
            EN_PORTB = SYSCTL_PERIPH_GPIOB,
            EN_PORTC = SYSCTL_PERIPH_GPIOC,
            EN_PORTD = SYSCTL_PERIPH_GPIOD,
            EN_PORTE = SYSCTL_PERIPH_GPIOE,
            EN_PORTF = SYSCTL_PERIPH_GPIOF,
            EN_PORTG = SYSCTL_PERIPH_GPIOG,
            EN_PORTH = SYSCTL_PERIPH_GPIOH

}port_enable_t;

typedef enum{
            PIN0 = GPIO_INT_PIN_0,
            PIN1 = GPIO_INT_PIN_1,
            PIN2 = GPIO_INT_PIN_2,
            PIN3 = GPIO_INT_PIN_3,
            PIN4 = GPIO_INT_PIN_4,
            PIN5 = GPIO_INT_PIN_5,
            PIN6 = GPIO_INT_PIN_6,
            PIN7 = GPIO_INT_PIN_7

}pin_index_t;

typedef enum{
            PORTA = GPIO_PORTA_BASE,
            PORTB = GPIO_PORTB_BASE,
            PORTC = GPIO_PORTC_BASE,
            PORTD = GPIO_PORTD_BASE,
            PORTE = GPIO_PORTE_BASE,
            PORTF = GPIO_PORTF_BASE,
            PORTG = GPIO_PORTG_BASE,
            PORTH = GPIO_PORTH_BASE

}port_index_t;

typedef struct{
            uint32_t port      ;
            uint8_t  pin       ;
            uint32_t pinio     ;

}pin_config_t;

/*  Macro Function Dec  */


/*      Function Dec   */

/*Function Dec*/

Std_ReturnType gpio_pin_direction_intialize(port_index_t port, port_enable_t port_enable , direction_t direction, uint8_t pins);
//
Std_ReturnType gpio_pin_write_logic(port_index_t port, uint8_t pins, uint8_t logic);
Std_ReturnType gpio_pin_read_logic(port_index_t port, uint8_t pins, uint32_t * save_logic);

///*'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/
Std_ReturnType gpio_port_enable(port_index_t port, port_enable_t port_enable);
Std_ReturnType gpio_port_direction_intialize(port_index_t port, port_enable_t port_enable, direction_t direction);

Std_ReturnType gpio_port_write_logic(port_index_t port, uint8_t logic);
Std_ReturnType gpio_port_read_logic(port_index_t port, uint32_t *save_logic);


#endif /* MCAL_LAYER_GPIO_HAL_GPIO_H_ */
