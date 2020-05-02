#ifndef _SSD1306_PMOD_H
#define _SSD1306_PMOD_H
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

#include <Cariad.h>
#include <SSD1306.h>
#include <DSPI.h>

class SSD1306_PMOD : public SSD1306 {

    protected:
        static const int DC_DATA = HIGH;
        static const int DC_COMMAND = LOW;

        DSPI *_spi;
        int _cs;
        int _dc;
        int _reset;

        virtual void command(uint8_t c);
        virtual void command(uint8_t c1, uint8_t c2);
        virtual void command(uint8_t c1, uint8_t c2, uint8_t c3);
        virtual void data(uint8_t d);

    public:
        SSD1306_PMOD(DSPI &spi, int cs, int dc, int reset = -1) : 
            _spi(&spi), _cs(cs), _dc(dc), _reset(reset), SSD1306(128, 32) {}
        SSD1306_PMOD(DSPI *spi, int cs, int dc, int reset = -1) : 
            _spi(spi), _cs(cs), _dc(dc), _reset(reset), SSD1306(128, 32) {}

        virtual void initializeDevice();
};


#endif
