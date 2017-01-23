#define _16bitpwm

void setupPWM16() {
  TCCR1A = _BV(COM1A1) | _BV(COM1B1)  /* non-inverting PWM */
           | _BV(WGM11);                   /* mode 14: fast PWM, TOP=ICR1 */
  TCCR1B = _BV(WGM13) | _BV(WGM12)
           | _BV(CS11);                    /* prescaler 1 */
  ICR1 = 0x03ff;                      /* TOP counter value (freeing OCR1A*/

  DDRB |= _BV(PB1) | _BV(PB2);

}
void analogWrite16(uint8_t pin, int val)
{
  switch (pin) {
    case 9: OCR1A = val; break;
    case 10: OCR1B = val; break;

  }
}

/*
   * for 10 bit , set as 0x03ff,confirmed-MALHAR
   * frequency= 15.625KHz for 16Mhz CPU clock
   * frequency=  7.812KHz for 8Mhz CPU clock
  */

/*
* Comments about the setup
* Changing ICR1 will effect the amount of bits of resolution.
* ICR1 = 0xffff; (65535) 16-bit resolution
* ICR1 = 0x7FFF; (32767) 15-bit resolution
* ICR1 = 0x3FFF; (16383) 14-bit resolution etc....

* Changing the prescaler will effect the frequency of the PWM signal.
* Frequency[Hz}=CPU/(ICR1+1) where in this case CPU=16 MHz
* 16-bit PWM will be>>> 16000000/(65535+1)=244.14Hz
* 
* Original Code skleton was borrowed from followig thread
* "http://arduino.stackexchange.com/questions/12718/increase-pwm-bit-resolution"
* -MALHAR
*/

/*CHANGELOG
 * #Fri 11/04/2016, 21:05:06.43
 * Started adding changlog on Fri 11/04/2016, 21:05:06.43
 * Removed TEST_ON_MEGA as it is not required in this application
 * by Malhar Deshmukh(MalharD)
 */
