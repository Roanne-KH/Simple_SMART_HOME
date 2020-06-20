
#include"DIO.h"
void PINCas(char pinNum, char dir) {
    switch (dir) {
        case OUT:
            DDRC |= (1 << pinNum);
            break;
        case IN:
            DDRC &= ~(1 << pinNum); // SET INPUT PIN (0) OF PORT B
            break;

    }
}
void setPINC(char pinNum) {
    PORTC |= (1 << pinNum);
}
void resetPINC(char pinNum) {
    PORTC &=~ (1 << pinNum);
}
