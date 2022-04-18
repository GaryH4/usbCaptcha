#include <stdio.h>
#include "esp_system.h"
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include "freertos/task.h"
#include "oled.h"
#include "fonts.h"
#include "genRandom.h"

#define DR_REG_RNG_BASE1 0x3F435000
#define DR_REG_RNG_BASE2 0x60035000

void app_main()
{
    oled_init();

    while (1)
    {
        char captcha[6] = "\0";
        genRandomString(captcha, 5);
        printf("captcha: %s\n", captcha);

        oled_show_str(0, 0, "USB Captcha Rev2.0", &Font_7x10, 1);
        oled_show_str(0, 18, "type in:", &Font_7x10, 1);
        oled_show_str(64, 18, captcha, &Font_7x10, 1);
        oled_show_str(20, 40, captcha, &Font_11x18, 1);

        vTaskDelay(5000 / portTICK_PERIOD_MS); // TODO: change to 15000ms in production
        oled_claer();
    }

    // TODO: blink LEDs
    // TODO: read from usb keyboard
    // TODO: print oled from usb keyboard
    // TODO: check keyboard input
    // TODO: switch usb signal
}
