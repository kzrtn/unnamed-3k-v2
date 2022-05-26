#define F_CPU 16000000UL
#ifndef __AVR_ATmega32U2__
#define __AVR_ATmega32U2__
#endif

int main(void) {

    PORTB = (1<<PB4)|(1<<PB6)|(1<<PB7);
    DDRB = (1<<DDB3)|(0<<DDB4)|(1<<DDB5)|(0<<DDB6)|(0<<DDB7);

    return 0;
}