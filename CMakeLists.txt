# blink for RP2040 Zero

cmake_minimum_required(VERSION 3.13)

# Pull in SDK
include(pico_sdk_import.cmake)
include(pico_extras_import.cmake)

set(PICO_BOARD waveshare_rp2040_zero)

project(pico_blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Init the SDK
pico_sdk_init()

# Add executable target
add_executable(pico_mp3
  mp3.c
)

# Link std lib
target_link_libraries(pico_mp3
  pico_stdlib
  hardware_pio
  pico_audio_i2s
)

# Enable USB (CDC) or UART
pico_enable_stdio_usb(pico_mp3 1)
pico_enable_stdio_uart(pico_mp3 0)

# Generate extra build outputs
pico_add_extra_outputs(pico_mp3)
