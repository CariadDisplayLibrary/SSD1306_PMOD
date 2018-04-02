/*
 * Copyright (c) 2015, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 * 
 * * Neither the name of Majenko Technologies nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <SSD1306_PMOD.h>

void SSD1306_PMOD::initializeDevice() {
    _spi->begin();
    _spi->setSpeed(20000000UL);
    pinMode(_cs, OUTPUT);
    digitalWrite(_cs, HIGH);
    pinMode(_dc, OUTPUT);
    digitalWrite(_dc, DC_COMMAND);

    if (_reset >= 0) {
        pinMode(_reset, OUTPUT);
        digitalWrite(_reset, HIGH);
        delay(100);
        digitalWrite(_reset, LOW);
        delay(100);
        digitalWrite(_reset, HIGH);
    }

    initDevice();
}

void SSD1306_PMOD::command(uint8_t c) {
    digitalWrite(_dc, DC_COMMAND);
    digitalWrite(_cs, LOW);
    _spi->transfer(c);
    digitalWrite(_cs, HIGH);
}

void SSD1306_PMOD::command(uint8_t c1, uint8_t c2) {
    digitalWrite(_dc, DC_COMMAND);
    digitalWrite(_cs, LOW);
    _spi->transfer(c1);
    _spi->transfer(c2);
    digitalWrite(_cs, HIGH);
}

void SSD1306_PMOD::command(uint8_t c1, uint8_t c2, uint8_t c3) {
    digitalWrite(_dc, DC_COMMAND);
    digitalWrite(_cs, LOW);
    _spi->transfer(c1);
    _spi->transfer(c2);
    _spi->transfer(c3);
    digitalWrite(_cs, HIGH);
}

void SSD1306_PMOD::data(uint8_t c) {
    digitalWrite(_dc, DC_DATA);
    digitalWrite(_cs, LOW);
    _spi->transfer(c);
    digitalWrite(_cs, HIGH);
}
