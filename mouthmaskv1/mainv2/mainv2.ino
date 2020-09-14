#include <WS2812FX.h>

#define LED_COUNT 7
#define LED_PIN D2

#define ANALOG_PIN A0
#define ANALOG_THRESHOLD 512

#define TIMER_MS 3000

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

unsigned long last_trigger = 0;
unsigned long now = 0;

void setup() {
  ws2812fx.init();
  ws2812fx.setBrightness(100);
  ws2812fx.setMode(FX_MODE_LARSON_SCANNER);
  ws2812fx.setSpeed(70000);
}

void loop() {
  now = millis();
  ws2812fx.service();
  if(analogRead(ANALOG_PIN) > ANALOG_THRESHOLD) {
    ws2812fx.trigger();
    ws2812fx.setBrightness(100);
  } else {
    ws2812fx.setBrightness(0);
  }
}
