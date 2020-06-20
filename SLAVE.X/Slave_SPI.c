
#include"Slave_SPI.h"
void SPI_Slave_init() {
    // Data Direction Configuration
    DDRB |= (1 << MISO);
    SPCR |= (1 << SPE) | (1 << SPR1) | (1 << SPR0); //| (1 << SPIE);
}
char SPI_Read() {
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}
