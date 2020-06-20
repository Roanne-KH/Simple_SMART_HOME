#include<xc.h>
#include "UART.h"

void UART_init() { // UART Initiation
    //TX
    UCSRB |= (1 << TXEN); // Enable Transmitter

    //RX
    UCSRB |= (1 << RXEN); /// Enable Receiver
    UCSRB |= (1 << RXCIE); /// Enable RXC Interrupt
    //UCSRC |= (1<<URSEL)|(1<<USBS);    //STOPBIT=2BITS

    // BaudRate
    UBRRL = 103; //BaudRate 9600bps
}
//1 stopbit   , no parity bit ,Asynchronus clock, receive 5 databits

void transmitChar(char data) { // Transmitting Character
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}

void transmitString(char *data) {// Transmitting String
    for (int i = 0; data[i] != '\0'; i++) {
        transmitChar(data[i]);
    }
}



