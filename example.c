#include <msp430g2553.h>
#include "sensor.h"
/*
 * main.c
 */

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	initADC10();
	initLEDs();

	for (;;) {



		if (leftsensor() < 0x236)
			P1OUT = ~BIT0;

		else
			P1OUT |= BIT0;

		_delay_cycles(400);


		if (rightsensor() < 0x236)
			P1OUT &= ~BIT6;

		else
			P1OUT |= BIT6;


}
		return 0;

}
