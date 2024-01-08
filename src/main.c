// Constants
#define F_CPU 16000000UL    // Arduino board clock frequency: 16 Mhz

// Header Files
#include <avr/io.h>         // Pin definitions for AVR
#include <util/delay.h>     // Delay functions for AVR

// Main Program
int main(void) {

    // Setting the value of DDRD
    // Default value of DDRD is 0000 0000
    int valueToSetDDRD = 0b10000000;         // Bitmask for DDRD to set D7 to 1
    DDRD = DDRD | valueToSetDDRD;            // Carries out OR between 0000 0000 and 1000 0000              

    // Bitmasks
    int compareOnBitmask = 0b01000000;       // Bitmask where PIN6 is reading HIGH (1)
    int valueHighBitmask = 0b10000000;       // Bitmask for PORTD to set D7 to 1
    int valueLowBitmask = 0b01111111;        // Bitmask for PORTD to set D7 to 0, leave all other states alone

    // Main Loop
    while(1) {
        // If PIN D6 is reading HIGH then == 0100 0000 is TRUE
        if ((PIND & compareOnBitmask) == 0b01000000){
            // Set PORT D7 to HIGH
            PORTD = PORTD | valueHighBitmask;           // Carries out OR between 0000 0000 and 1000 000
        } else {
            // Set PORT PD7 to LOW
            PORTD = PORTD & valueLowBitmask;           // Carries out AND between 1000 0000 and 0000 0000
        }
    }
    return 0;
}