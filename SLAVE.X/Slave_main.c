/*
 * File:   Slave_main.c
 * Author: Roanne
 *
 * Created on June 20, 2020, 11:31 AM
 */

#define F_CPU 16000000UL
#include <xc.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "Slave_Config.h" 

int main(void) {
    // Actuators to be controlled as Output 
    PINCas(LED1, OUT); // LED1 AS OUT
    PINCas(LED2, OUT); // LED2 AS OUT

    // Slave initiation  
    SPI_Slave_init();

    while (1) {
        data = SPI_Read();
        
        // CHECK RECEIVED DATA 
        if (data == on_led1) PORTC |= (1 << LED1);
        else if (data == off_led1) PORTC &= ~(1 << LED1);
        else if (data == on_led2) PORTC |= (1 << LED2);
        else if (data == off_led2) PORTC &= ~(1 << LED2);

    }
}
