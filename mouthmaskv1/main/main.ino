#include <WS2812FX.h>

#define LED_COUNT 7
#define LED_PIN D2

#define SENSOR_PIN D0

#define TIMER_MS 3000
WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);


unsigned long last_trigger = 0;
unsigned long now = 0;

void setup() {
  ws2812fx.init();
  ws2812fx.setBrightness(255);
  ws2812fx.setMode(FX_MODE_RAINBOW);
}

void loop() {
  now = millis();
  ws2812fx.service();
  if(digitalRead(SENSOR_PIN) > 0.8) {
    ws2812fx.trigger();
    ws2812fx.setBrightness(255);
  } else {
    ws2812fx.setBrightness(10);
  }
}
