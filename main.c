
#include "io.h"
#include "LiquidCrystal.h"

/*
 * Written for the Intel Quark D2000 development kit using the Intel® Quark™ Microcontroller Software Interface
 *
 * A quick and dirty adaptation of the Arduino LiquidCrystal library for the
 * HD44780 type LCD displays.
 *
 * Original source files: https://github.com/arduino/Arduino/tree/master/libraries/LiquidCrystal/src
 *
 * These files only implement the 4 bit data interface and the R/W pin is not used.
 * Please find the pins used in the io.h file.
 *
 * You may find these sites useful:
 * https://software.intel.com/en-us/iot/hardware/d2000		Intel® Quark™ Microcontroller Developer Kit D2000
 * https://omerk.github.io/lcdchargen/ 						char generator for custom chars
 * https://cdn-shop.adafruit.com/datasheets/HD44780.pdf 	Data sheet for HD44780
 * https://www.menie.org/georges/embedded/small_printf_source_code.html		a small printf (Print.c)
 * https://software.intel.com/en-us/node/734340				Intel Quark D2000 kit pin map
 * https://software.intel.com/en-us/issm-2016-user-ref-guide-update2 		Intel ISSM reference guide
 * http://www.intel.com/content/dam/www/public/us/en/documents/design-guides/quark-d2000-customer-reference-board.pdf
 * https://learn.adafruit.com/character-lcds?view=all		How to wire up the LCD
 * https://create.arduino.cc/projecthub/microBob/lcd-liquid-crystal-display-e72c74
 * https://www.arduino.cc/en/Reference/LiquidCrystal
 *
 */

int main(void)
{
	QM_pin_setup();	// Set up output pins
	LiquidCrystal(LCD_RS, LCD_EN, LCD_DB_4, LCD_DB_5, LCD_DB_6, LCD_DB_7);

	/*
	 * This printf function will accept integer formats (%d, %x, %X, %u), string format (%s)
	 * and character format (%c); left and right alignment, padding with space or 'O'.
	 * Note: "\n" is not implemented in this version. The HD44780 doesn't support vertical scrolling.
	 * It may be done by writing all text to a buffer, which is then used to refresh the display.
	*/

	// Tested:
	//printf("Color %s", "red");			/* Renders: "Color red"      */
	//printf("number1 %d", 123456);			/* Renders: "number1 123456" */
	//printf("number2 %05d", 89);			/* Renders: "number2 00089"  */
	//printf("number3 %*d", 5, 10);			/* Doesn't work!             */
	//printf("hex %#x,", 255);				/* Doesn't work!             */
	//printf("hex %x", 255);				/* Renders : "hex ff"        */
	//printf("hex %X", 255);				/* Renders : "hex FF"        */
	//printf("unsigned %u", 250);			/* Renders : "unsigned 250"  */

	printf("HD44780 %c%c%c",'L', 'C','D');
	setCursor(0,1);
	// Custom chars: (defined in LiquidCrystal.c)
	printf("ÆØÅæøåg°");

}
