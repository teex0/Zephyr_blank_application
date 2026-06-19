#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED_NODE DT_ALIAS(led0)
#define BUTTON_NODE DT_ALIAS(sw0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(BUTTON_NODE, gpios);

int main(void)
{
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure_dt(&button, GPIO_INPUT);

    while (1) {

        int val = gpio_pin_get_dt(&button);

        if (val == 1){
            gpio_pin_set_dt(&led, 0);
        } else {
            gpio_pin_set_dt(&led, 1);
        }
        k_sleep(K_MSEC(50));
    }
}