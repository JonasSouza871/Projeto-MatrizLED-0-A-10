# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PICO_BOARD pico_w CACHE STRING "Board type")
include(pico_sdk_import.cmake)

project(ws2812 C CXX ASM)  # Mantém o nome do projeto como "ws2812"
pico_sdk_init()

# Adiciona o executável principal (arquivo .c renomeado para main.c)
add_executable(ws2812
    main.c          # Arquivo principal renomeado
    matriz_led.c    # Funções da matriz de LED
    numeros.c       # Padrões dos números
)

# Gera o cabeçalho PIO a partir do arquivo **ws2812.pio** (nome mantido)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/generated)
pico_generate_pio_header(ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

# Vincula as bibliotecas necessárias
target_link_libraries(ws2812 PRIVATE
    pico_stdlib
    hardware_pio
)

# Gera arquivos .uf2 e .hex
pico_add_extra_outputs(ws2812)