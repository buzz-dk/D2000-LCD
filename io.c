
#include <inttypes.h>
#include "clk.h"
#include "qm_gpio.h"
#include "qm_pinmux.h"
#include "qm_pin_functions.h"
#include "io.h"

// Global until further:
qm_gpio_port_config_t cfg;

// Arduino function rewritten:
void digitalWrite(uint8_t pin, uint8_t value)
{
	if(value==0x00)
		qm_gpio_clear_pin(QM_GPIO_0, pin);
	else qm_gpio_set_pin(QM_GPIO_0, pin);
}

// Arduino function rewritten:
inline void delayMicroseconds(unsigned long delay)
{
	clk_sys_udelay(delay);
}

void QM_pin_setup(void)
{
  qm_pmux_select(LCD_DB_4, QM_PIN_0_FN_GPIO_0);
  qm_pmux_select(LCD_DB_5, QM_PIN_0_FN_GPIO_0);
  qm_pmux_select(LCD_DB_6, QM_PIN_0_FN_GPIO_0);
  qm_pmux_select(LCD_DB_7, QM_PIN_0_FN_GPIO_0);
  qm_pmux_select(LCD_RS, QM_PIN_0_FN_GPIO_0);
  qm_pmux_select(LCD_EN, QM_PIN_0_FN_GPIO_0);

  /* write GPIO port configuration. */
  cfg.direction = BIT(LCD_DB_4) |
		          BIT(LCD_DB_5) |
				  BIT(LCD_DB_6) |
				  BIT(LCD_DB_7) |
				  BIT(LCD_RS) |
				  BIT(LCD_EN);

  qm_gpio_set_config(QM_GPIO_0, &cfg);
}

