cmake_minimum_required(VERSION 3.20.0)

cmake_minimum_required(VERSION 3.20.0)

# IMPORTANT Switch toolchain 
set(ZEPHYR_TOOLCHAIN_VARIANT "espressif")

# set board variable to thingy:52
#set(BOARD "thingy52_nrf52832")
set(BOARD "esp32")

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(ble_scanner)

target_sources(app PRIVATE src/main.c)

# I'm not sure why, but this is required for ESP32
zephyr_library_include_directories(${ZEPHYR_BASE}/samples/bluetooth)
