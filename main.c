#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();
    printf("ADC Example, measuring GPIO26\n");

    adc_init();

    adc_set_temp_sensor_enabled (true);

    adc_select_input(4);

    gpio_init (25);

    gpio_set_dir (25,true);

    while (1) {

        const float conversion_factor = 3.3f / (1 << 12);
        uint16_t result = adc_read();

        float T = 27 - (result - 0.706)/0.001721;

        printf("Raw value: 0x%03x, voltage: %.2f V\n,", T, result, result * conversion_factor);
        sleep_ms(500);
    }
}
