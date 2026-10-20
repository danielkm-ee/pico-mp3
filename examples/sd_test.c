/* sd_test.c
Copyright (c) 2026 Daniel Monahan

*/

#include <stdio.h>

#if PICO_ON_DEVICE
#include "pico/stdlib.h"
#endif

#include "hw_config.h"
#include "f_util.h"
#include "ff.h"

FRESULT ls_dir(const char* path) {
  FRESULT res;
  DIR dir;
  FILINFO fno;

  res = f_opendir(&dir, path);
  if (res != FR_OK) {
    panic("f_opendir error: %s (%d)\n", FRESULT_str(res), res);
    return res;
  }

  for (;;) {
    res = f_readdir(&dir, &fno);
    if (res != FR_OK || fno.fname[0] == 0) {
      break; // error or end of dir reached
    }
    if (fno.fattrib & AM_DIR) {
      printf(" [DIR] %s\n", fno.fname);
    } 
    else {
      printf("%9lu B  %s\n", (unsigned long)fno.fsize, fno.fname);
    }
  }
  f_closedir(&dir);
  return res;
}

int main(void) {
  stdio_init_all();

  puts("running sd_test.c: opening sd card and listing files present");

  /* create and mount file system to device root */
  FATFS fs;
  FRESULT fr = f_mount(&fs, "", 1);
  if (FR_OK != fr) {
    panic("f_mount error: %s (%d)\n", FRESULT_str(fr), fr);
  }

  while(true) {
    int c = getchar_timeout_us(0);
    if (c) {
      FRESULT res;
      DIR dir;
      FILINFO fno;

      res = f_opendir(&dir, "");
      if (res != FR_OK) {
        panic("f_opendir error: %s (%d)\n", FRESULT_str(res), res);
        return res;
      }

      for (;;) {
        res = f_readdir(&dir, &fno);
        if (res != FR_OK || fno.fname[0] == 0) {
          break; // error or end of dir reached
        }
        if (fno.fattrib & AM_DIR) {
          printf(" [DIR] %s\n", fno.fname);
        } 
        else {
          printf("%9lu B  %s\n", (unsigned long)fno.fsize, fno.fname);
        }
      }
      f_closedir(&dir);
    }
  }
  
  return 0;
}
