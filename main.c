// Blink both the LEDs on the board and an external LED in a sequence

#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1OUT &= ~0x07;                         // Clear P1.0, P1.1, P1.2 output latch for a defined power-on state
    P1DIR |= 0x07;                          // Set P1.0, P1.1, P1.2 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        P1OUT = 0x01;
        __delay_cycles(300000);
        P1OUT = 0x02;
        __delay_cycles(300000);
        P1OUT = 0x04;
        __delay_cycles(300000);
    }
}
