/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/lite/micro/examples/hello_world/main_functions.h"

#include "m5stick.h"
#include "lcd.h"
#include "fpioa.h"
#include "global_config.h"

void setup_lcd(uint16_t fillColor, lcd_dir_t lcdDirection)
{
    fpioa_set_function(21, static_cast<_fpioa_function>(FUNC_GPIOHS0 + RST_GPIONUM));
    fpioa_set_function(20, static_cast<_fpioa_function>(FUNC_GPIOHS0 + DCX_GPIONUM));
    fpioa_set_function(22, static_cast<_fpioa_function>(FUNC_SPI0_SS0 + LCD_SPI_SLAVE_SELECT));
    fpioa_set_function(19, FUNC_SPI0_SCLK);
    fpioa_set_function(18, FUNC_SPI0_D0);

    lcd_init(CONFIG_LCD_DEFAULT_FREQ, false, 52, 40, 40, 52, true, CONFIG_LCD_DEFAULT_WIDTH, CONFIG_LCD_DEFAULT_HEIGHT);
    lcd_set_direction(lcdDirection);
    lcd_clear(fillColor);
}

// This is the default main used on systems that have the standard C entry
// point. Other devices (for example FreeRTOS or ESP32) that have different
// requirements for entry code (like an app_main function) should specialize
// this main.cc file in a target-specific subfolder.
int main(int argc, char* argv[]) {
  m5stick_init();

  setup_lcd(BLACK, DIR_YX_LRUD);

  setup();
  while (true) {
    loop();
  }
}
