
#ifndef IO_H_
#define IO_H_

#include <inttypes.h>
#include "qm_gpio.h"
#include "qm_pinmux.h"
#include "qm_pin_functions.h"

// Quark output pins for display:
#define LCD_RS (QM_PIN_ID_8)	// LCD pin #4	RS	Register select
#define LCD_EN (QM_PIN_ID_5)	// LCD pin #6	EN	Enable - starts data write.
#define LCD_DB_4 (QM_PIN_ID_10)	// LCD pin #11	DB4	data transfer
#define LCD_DB_5 (QM_PIN_ID_11)	// LCD pin #12	DB5	data transfer
#define LCD_DB_6 (QM_PIN_ID_12)	// LCD pin #13	DB6	data transfer
#define LCD_DB_7 (QM_PIN_ID_13)	// LCD pin #14	DB7	data transfer

void digitalWrite(uint8_t pin, uint8_t value);
void delayMicroseconds(unsigned long delay);
void QM_pin_setup(void);

#endif /* IO_H_ */
