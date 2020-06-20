/*
 * File:   Master_main.c
 * Author: Roanne
 *
 * Created on June 20, 2020, 11:20 AM
// */

#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include "Master_Config.h"

ISR(USART_RXC_vect) {
    char Rec = UDR;
    // Check UDR VALUE  
    if (Rec == 'O') { // Turn ON LED 1
        SPI_write(on_led1);
        setPINC(TEST_LED);
        transmitString(str3);
        transmitString(str1);
        
    } else if (Rec == 'C') {// Turn OFF LED 1
        SPI_write(off_led1);
        resetPINC(TEST_LED);
        transmitString(str3);
        transmitString(str2);
        
    } else if (Rec == 'A') {// Turn ON LED 2

        SPI_write(on_led2);
        transmitString(str3);
        transmitString(str5);
        setPINC(TEST_LED);

    } else if (Rec == 'B') {// Turn OFF LED 2

        SPI_write(off_led2);
        transmitString(str3);
        transmitString(str6);
        resetPINC(TEST_LED);

    } else { // Invalid Input 

        transmitString(str3);
        transmitString(str4);
    }
}

int main(void) {
    /* Replace with your application code */
    PINCas(TEST_LED, OUT); //Testing UART , MASTER AS RX
    UART_init(); // UART INITIATION
    sei();
    transmitString(str7); // Choose which actuator to turn ON.
    SPI_Master_init(); // SPI INITIATION


    while (1) {
    }
}