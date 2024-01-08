// Constants
#define F_CPU 16000000UL    // Arduino board clock frequency: 16 Mhz

// Header Files
#include <avr/io.h>         // Pin definitions for AVR
#include <util/delay.h>     // Delay functions for AVR

// Main Program
int main(void) {

    // Setting the value of DDRD
    // Default value of DDRD is 0000 0000
    int valueToSetDDRD = 0b10000000;   // Bitmask for DDRD to set D7 to 1
    DDRD = DDRD | valueToSetDDRD;      // Carries out OR between 0000 0000 and 1000 0000              

    // Main Loop
    while(1) {
        // If PIN D6 is HIGH
        
            // Set PORT D7 to HIGH
            // Default value of PORTD is 0000 0000
            int valueHighBitmask = 0b10000000;          // Bitmask for PORTD to set D7 to 1
            PORTD = PORTD | valueHighBitmask;           // Carries out OR between 0000 0000 and 1000 000

        // Else

            // Set PORT PD7 to LOW
            // Assuming value of PORTD is 1000 0000
            int valueLowBitmask = 0b01111111;          // Bitmask for PORTD to set D7 to 0, leave all other states alone
            PORTD = PORTD & valueLowBitmask;           // Carries out AND between 1000 0000 and 0000 0000
    }
    return 0;
}