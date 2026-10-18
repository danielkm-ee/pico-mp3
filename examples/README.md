# Example programs
The following example programs were built during the development phase and are left here as reference.

## sine.c (modified version of pico-playground/audio/sine_wave.c)
This example plays a single sine tone over I2S and provides a USB interface to control the tone frequency and volume.
### controls
- (`-`, `=`) volume (down, up)
- (`[`, `]`) frequency (low, high)

### build & flash from pico-mp3/build with
```
make sine && \
load -x sine.uf2
```

### open serial using minicom
```
minicom -D /dev/ttyACM0
```

## sd_test.c
This example mounts an SD card and lists the files present.

### build & flash from pico-mp3/build with
```
make sd_test && \
load -x sd_test.uf2
```

### open serial using minicom
```
minicom -D /dev/ttyACM0
```


