
/* hw_config.c
configuration for SD card library
https://github.com/carlk3/no-OS-FatFS-SD-SDIO-SPI-RPi-Pico

Copyright 2021 Carl John Kugler III
Modifications Copyright (c) 2026 Daniel Monahan 

Licensed under the Apache License, Version 2.0 (the License); you may not use
this file except in compliance with the License. You may obtain a copy of the
License at

   http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an AS IS BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.

danielkm-ee tailored this hardware configuration for this project
https://github.com/danielkm-ee/pico-mp3
*/

#include "config.h"     /* config for pico-mp3 */
#include "hw_config.h"

/* hardware SPI object */
static spi_t spi = {
    .hw_inst = spi0,
    .sck_gpio = SD_SCLK, 
    .mosi_gpio = SD_MOSI,
    .miso_gpio = SD_MISO,
    .baud_rate = 125 * 1000 * 1000 / 8  // 15625000 Hz
    //.baud_rate = 125 * 1000 * 1000 / 6  // 20833333 Hz
    //.baud_rate = 125 * 1000 * 1000 / 4  // 31250000 Hz
    //.baud_rate = 125 * 1000 * 1000 / 2  // 62500000 Hz
};

/* SPI Interface */
static sd_spi_if_t spi_if = {
    .spi = &spi,
    .ss_gpio = SD_CS
};

/* SD Card socket object */
static sd_card_t sd_card = {
    .type = SD_IF_SPI,
    .spi_if_p = &spi_if
};

size_t sd_get_num() { return 1; }

sd_card_t *sd_get_by_num(size_t num) {
    if (0 == num) {
        // The number 0 is a valid SD card number.
        // Return a pointer to the sd_card object.
        return &sd_card;
    } else {
        // The number is invalid. Return @c NULL.
        return NULL;
    }
}

