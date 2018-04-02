#include <DSPI.h>
#include <SSD1306.h>
#include <SSD1306_PMOD.h>

/* NOTE:
 * 
 * For the Digilent Basic IO Shield OLED you will need to make a small hardware
 * modification for reliable operation. For some reason they tied the CS pin of
 * the OLED to ground through a resistor. This is incorrect, since we need to have
 * control of the CS pin since it is part of the SPI protocol specification. So
 * you need to solder a wire from the OLED connector side of R34 (it's by the
 * soldered OLED ribon connector - you want the side closest to the ribon connector)
 * to any available IO pin.  Pin 41 is the most convenient - it isn't used by anything
 * else on the IO shield, and is close to R34.
 */

// These are the pins for the Digilent Basic IO Shield OLED.
const int reset = 10;
const int dc = 39;
const int cs = 41; // Choose an unused pin and wire the CS signal to it. 41 is a good choice.

DSPI0 spi;
SSD1306_PMOD tft(spi, cs, dc, reset);

void setup() {
    tft.initializeDevice();
    tft.setBacklight(255);
    tft.fillScreen(Color::Black);
    tft.drawRectangle(0, 0, 127, 31, Color::White);
}

void loop() {
    tft.setCursor(10, 10);
    tft.print(millis());
}
