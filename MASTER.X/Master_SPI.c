/*
 * File:   Master_SPI.c
 * Author: Roanne
 *
 * Created on June 20, 2020, 5:18 PM
 */
#include <xc.h> 
#include "Master_SPI.h"

#define SS      4
#define MOSI    5
#define MISO    6
#define SCK     7



void SPI_Master_init() { // SPI Initiation
    // Data Direction Configuration
    DDRB |=  (1 << MOSI) | (1 << SCK)|(1 << SS); //  OUTPUTS 
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0); 
}

void SPI_write(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF))); // To check transmission of data
}
