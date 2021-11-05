/*
    MIT License

    Copyright (c) 2017-2019, Alexey Dynda

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#include "ssd1306.h"
#include "nano_gfx.h"
#include "sova.h"
#include "gifdec.h"

#define RK3399_GPIO1_A0 32
#define RK3399_GPIO1_A1 33
#define RK3399_SPIDEV 1

typedef struct {
    const uint8_t *data;
    uint16_t width;
    uint16_t height;
    uint8_t datasize;
} tImage;

const tImage penguin = { image_data_penguin, 128, 64, 8 };

void setup()
{
    int8_t rstPin;
    int8_t cesPin;
    int8_t dcPin;

    rstPin = RK3399_GPIO1_A1;
    cesPin = RK3399_SPIDEV;
    dcPin = RK3399_GPIO1_A0;

    /* Select the font to use with menu and all font functions */
    ssd1306_setFixedFont(ssd1306xled_font6x8);
    ssd1306_128x64_spi_init(rstPin, cesPin, dcPin);
    ssd1306_clearScreen();
}

void loop()
{
    delay(100);
}

int main(int argc, char *argv[])
{
    setup();
    ssd1306_drawXBitmap(0, 0, penguin.width, penguin.height, penguin.data);
}
