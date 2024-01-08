// Header Files
#include <avr/io.h>         // Pin definitions for AVR
#include <util/delay.h>     // Delay functions for AVR

// Constants
#define F_CPU 16000000UL    // Arduino board clock frequency: 16 Mhz

// Main Program
int main(void) {

    // Setting the value of DDRD
    int valueToSetDDRD = 0b10000000;   // We want to set DDRD to this value
    DDRD = DDRD | valueToSetDDRD;      // Carries out the OR operator on DDRD 
                                       // Given DDRD default value is 0b00000000

    // Main Loop
    while(1) {
        // If PIN D6 is HIGH
            // Set PORT D7 to HIGH
        // Else
            // Set PORT PD7 to LOW
    }
    return 0;
}