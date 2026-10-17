// pinout + definitions for mp3 player app
//


#define I2S_HZ 44100 /* HZ */


/* pinout */
#define SD_MISO 4
#define SD_CS   5
#define SD_SCLK 6
#define SD_MOSI 7

/* i2s
 * these need to be defined for audio_i2s to use my pins */
#define PICO_AUDIO_I2S_DATA_PIN 11         /* I2S DIN */
#define PICO_AUDIO_I2S_CLOCK_PIN_BASE 12   /* I2S BCLK */
// PICO_AUDIO_I2S_CLOCK_PIN_BASE + 1 (= I2S LRCLK)



