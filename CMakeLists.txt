# blink for RP2040 Zero

cmake_minimum_required(VERSION 3.13)

# Pull in SDK
set(PICO_BOARD waveshare_rp2040_zero)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(pico_sdk_import)
include(pico_extras_import)

project(pico_mp3 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Init the SDK
pico_sdk_init()

# Add libraries
add_subdirectory(lib/no-OS-FatFS-SD-SDIO-SPI-RPi-Pico/src)

# builds executable with USB
function(pico_mp3_executable name)
  target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) 
  pico_enable_stdio_usb(${name} 1)
  pico_enable_stdio_uart(${name} 0)
  pico_add_extra_outputs(${name})
endfunction()

# example : sine tone over i2s
add_executable(sine EXCLUDE_FROM_ALL examples/sine.c)
target_link_libraries(sine 
  pico_stdlib 
  hardware_pio 
  pico_audio_i2s
)
pico_mp3_executable(sine)

# example : mount sd card and list files
add_executable(sd_test EXCLUDE_FROM_ALL examples/sd_test.c hw_confic.c)
target_link_libraries(sd_test 
  pico_stdlib 
  no-OS-FatFS-SD-SDIO-SPI-RPi-Pico
)
# library diagnostics (optional)
target_compile_definitions(sd_test PRIVATE USE_PRINTF) 
pico_mp3_executable(sd_test)



