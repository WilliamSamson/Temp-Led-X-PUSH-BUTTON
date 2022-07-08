
#include <ezButton.h>

#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define DHTPIN 2     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT22     // DHT 22 (AM2302)
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        7 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 64 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels
int pinTemp = A0;

int buttonState1 = 5;
ezButton button(4);  // create ezButton object that attach to pin 7;
unsigned long lastCount = 0;
unsigned long count = 0;


void setup() {
  pinMode(buttonState1, INPUT_PULLUP);
  Serial.begin(9600);
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
  button.setCountMode(COUNT_FALLING);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  Serial.begin(9600);
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;

}
void hot () {
  pixels.setPixelColor(1, pixels.Color(50, 0, 0));
  pixels.setPixelColor(2, pixels.Color(50, 0, 0));
  pixels.setPixelColor(3, pixels.Color(50, 0, 0));
  pixels.setPixelColor(4, pixels.Color(50, 0, 0));
  pixels.setPixelColor(5, pixels.Color(50, 0, 0));
  pixels.setPixelColor(6, pixels.Color(50, 0, 0));
  pixels.setPixelColor(7, pixels.Color(50, 0, 0));
  pixels.setPixelColor(8, pixels.Color(50, 0, 0));
  pixels.setPixelColor(9, pixels.Color(50, 0, 0));
  pixels.setPixelColor(10, pixels.Color(50, 0, 0));
  pixels.setPixelColor(11, pixels.Color(50, 0, 0));
  pixels.setPixelColor(12, pixels.Color(50, 0, 0));
  pixels.setPixelColor(13, pixels.Color(50, 0, 0));
  pixels.setPixelColor(14, pixels.Color(50, 0, 0));
  pixels.setPixelColor(15, pixels.Color(50, 0, 0));
  pixels.setPixelColor(16, pixels.Color(50, 0, 0));
  pixels.setPixelColor(17, pixels.Color(50, 0, 0));
  pixels.setPixelColor(18, pixels.Color(50, 0, 0));
  pixels.setPixelColor(19, pixels.Color(50, 0, 0));
  pixels.setPixelColor(20, pixels.Color(50, 0, 0));

  pixels.setPixelColor(21, pixels.Color(50, 0, 0));
  pixels.setPixelColor(22, pixels.Color(50, 0, 0));
  pixels.setPixelColor(23, pixels.Color(50, 0, 0));
  pixels.setPixelColor(24, pixels.Color(50, 0, 0));
  pixels.setPixelColor(25, pixels.Color(50, 50, 50));
  pixels.setPixelColor(26, pixels.Color(50, 50, 50));
  pixels.setPixelColor(27, pixels.Color(50, 50, 50));
  pixels.setPixelColor(28, pixels.Color(50, 50, 50));
  pixels.setPixelColor(29, pixels.Color(50, 50, 50));
  pixels.setPixelColor(30, pixels.Color(50, 0, 0));
  pixels.setPixelColor(31, pixels.Color(50, 0, 0));
  pixels.setPixelColor(32, pixels.Color(50, 0, 0));
  pixels.setPixelColor(33, pixels.Color(50, 0, 0));
  pixels.setPixelColor(34, pixels.Color(50, 0, 0));
  pixels.setPixelColor(35, pixels.Color(50, 0, 0));
  pixels.setPixelColor(36, pixels.Color(50, 50, 50));
  pixels.setPixelColor(37, pixels.Color(50, 0, 0));
  pixels.setPixelColor(38, pixels.Color(50, 0, 0));
  pixels.setPixelColor(39, pixels.Color(50, 0, 0));
  pixels.setPixelColor(40, pixels.Color(50, 0, 0));
  pixels.setPixelColor(41, pixels.Color(50, 50, 50));
  pixels.setPixelColor(42, pixels.Color(50, 50, 50));
  pixels.setPixelColor(43, pixels.Color(50, 50, 50));
  pixels.setPixelColor(44, pixels.Color(50, 50, 50));
  pixels.setPixelColor(45, pixels.Color(50, 50, 50));
  pixels.setPixelColor(46, pixels.Color(50, 0, 0));
  pixels.setPixelColor(47, pixels.Color(50, 0, 0));
  pixels.setPixelColor(48, pixels.Color(50, 0, 0));
  pixels.setPixelColor(49, pixels.Color(50, 0, 0));
  pixels.setPixelColor(50, pixels.Color(50, 0, 0));
  pixels.setPixelColor(51, pixels.Color(50, 0, 0));
  pixels.setPixelColor(52, pixels.Color(50, 0, 0));
  pixels.setPixelColor(53, pixels.Color(50, 0, 0));
  pixels.setPixelColor(54, pixels.Color(50, 0, 0));
  pixels.setPixelColor(55, pixels.Color(50, 0, 0));
  pixels.setPixelColor(56, pixels.Color(50, 0, 0));
  pixels.setPixelColor(57, pixels.Color(50, 0, 0));
  pixels.setPixelColor(58, pixels.Color(50, 0, 0));
  pixels.setPixelColor(59, pixels.Color(50, 0, 0));
  pixels.setPixelColor(60, pixels.Color(50, 0, 0));
  pixels.setPixelColor(61, pixels.Color(50, 0, 0));
  pixels.setPixelColor(62, pixels.Color(50, 0, 0));
  pixels.setPixelColor(63, pixels.Color(50, 0, 0));
  pixels.setPixelColor(64, pixels.Color(50, 0, 0));
  pixels.setPixelColor(0, pixels.Color(50, 0, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void lesshot () {
  pixels.setPixelColor(1, pixels.Color(50, 0, 0));
  pixels.setPixelColor(2, pixels.Color(50, 0, 0));
  pixels.setPixelColor(3, pixels.Color(50, 0, 0));
  pixels.setPixelColor(4, pixels.Color(40, 5, 0));
  pixels.setPixelColor(5, pixels.Color(40, 5, 0));
  pixels.setPixelColor(6, pixels.Color(40, 5, 0));
  pixels.setPixelColor(7, pixels.Color(50, 0, 0));
  pixels.setPixelColor(8, pixels.Color(50, 0, 0));
  pixels.setPixelColor(9, pixels.Color(40, 5, 0));
  pixels.setPixelColor(10, pixels.Color(40, 5, 0));
  pixels.setPixelColor(11, pixels.Color(40, 5, 0));
  pixels.setPixelColor(12, pixels.Color(50, 0, 0));
  pixels.setPixelColor(13, pixels.Color(50, 0, 0));
  pixels.setPixelColor(14, pixels.Color(50, 0, 0));
  pixels.setPixelColor(15, pixels.Color(50, 0, 0));
  pixels.setPixelColor(16, pixels.Color(50, 0, 0));
  pixels.setPixelColor(17, pixels.Color(50, 0, 0));
  pixels.setPixelColor(18, pixels.Color(50, 0, 0));
  pixels.setPixelColor(19, pixels.Color(50, 0, 0));
  pixels.setPixelColor(20, pixels.Color(50, 0, 0));

  pixels.setPixelColor(21, pixels.Color(50, 0, 0));
  pixels.setPixelColor(22, pixels.Color(50, 0, 0));
  pixels.setPixelColor(23, pixels.Color(50, 0, 0));
  pixels.setPixelColor(24, pixels.Color(50, 0, 0));
  pixels.setPixelColor(25, pixels.Color(50, 0, 0));
  pixels.setPixelColor(26, pixels.Color(40, 5, 0));
  pixels.setPixelColor(27, pixels.Color(50, 0, 0));
  pixels.setPixelColor(28, pixels.Color(50, 0, 0));
  pixels.setPixelColor(29, pixels.Color(50, 0, 0));
  pixels.setPixelColor(30, pixels.Color(50, 0, 0));
  pixels.setPixelColor(31, pixels.Color(50, 0, 0));
  pixels.setPixelColor(32, pixels.Color(50, 0, 0));
  pixels.setPixelColor(33, pixels.Color(50, 0, 0));
  pixels.setPixelColor(34, pixels.Color(50, 0, 0));
  pixels.setPixelColor(35, pixels.Color(50, 0, 0));
  pixels.setPixelColor(36, pixels.Color(50, 0, 0));
  pixels.setPixelColor(37, pixels.Color(40, 5, 0));
  pixels.setPixelColor(38, pixels.Color(50, 0, 0));
  pixels.setPixelColor(39, pixels.Color(50, 0, 0));
  pixels.setPixelColor(40, pixels.Color(50, 0, 0));
  pixels.setPixelColor(41, pixels.Color(50, 0, 0));
  pixels.setPixelColor(42, pixels.Color(50, 0, 0));
  pixels.setPixelColor(43, pixels.Color(50, 0, 0));
  pixels.setPixelColor(44, pixels.Color(50, 0, 0));
  pixels.setPixelColor(45, pixels.Color(50, 0, 0));
  pixels.setPixelColor(46, pixels.Color(50, 0, 0));
  pixels.setPixelColor(47, pixels.Color(50, 0, 0));
  pixels.setPixelColor(48, pixels.Color(50, 0, 0));
  pixels.setPixelColor(49, pixels.Color(50, 0, 0));
  pixels.setPixelColor(50, pixels.Color(50, 0, 0));
  pixels.setPixelColor(51, pixels.Color(50, 0, 0));
  pixels.setPixelColor(52, pixels.Color(50, 0, 0));
  pixels.setPixelColor(53, pixels.Color(50, 0, 0));
  pixels.setPixelColor(54, pixels.Color(50, 0, 0));
  pixels.setPixelColor(55, pixels.Color(50, 0, 0));
  pixels.setPixelColor(56, pixels.Color(50, 0, 0));
  pixels.setPixelColor(57, pixels.Color(50, 0, 0));
  pixels.setPixelColor(58, pixels.Color(50, 0, 0));
  pixels.setPixelColor(59, pixels.Color(50, 0, 0));
  pixels.setPixelColor(60, pixels.Color(50, 0, 0));
  pixels.setPixelColor(61, pixels.Color(50, 0, 0));
  pixels.setPixelColor(62, pixels.Color(50, 0, 0));
  pixels.setPixelColor(63, pixels.Color(50, 0, 0));
  pixels.setPixelColor(64, pixels.Color(50, 0, 0));
  pixels.setPixelColor(0, pixels.Color(50, 0, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void lesserhot () {
  pixels.setPixelColor(1, pixels.Color(50, 0, 0));
  pixels.setPixelColor(2, pixels.Color(50, 0, 0));
  pixels.setPixelColor(3, pixels.Color(50, 0, 0));
  pixels.setPixelColor(4, pixels.Color(40, 10, 0));
  pixels.setPixelColor(5, pixels.Color(40, 10, 0));
  pixels.setPixelColor(6, pixels.Color(40, 10, 0));
  pixels.setPixelColor(7, pixels.Color(50, 0, 0));
  pixels.setPixelColor(8, pixels.Color(50, 0, 0));
  pixels.setPixelColor(9, pixels.Color(40, 10, 0));
  pixels.setPixelColor(10, pixels.Color(40, 10, 0));
  pixels.setPixelColor(11, pixels.Color(40, 10, 0));
  pixels.setPixelColor(12, pixels.Color(50, 0, 0));
  pixels.setPixelColor(13, pixels.Color(50, 0, 0));
  pixels.setPixelColor(14, pixels.Color(50, 0, 0));
  pixels.setPixelColor(15, pixels.Color(50, 0, 0));
  pixels.setPixelColor(16, pixels.Color(50, 0, 0));
  pixels.setPixelColor(17, pixels.Color(50, 0, 0));
  pixels.setPixelColor(18, pixels.Color(50, 0, 0));
  pixels.setPixelColor(19, pixels.Color(50, 0, 0));
  pixels.setPixelColor(20, pixels.Color(50, 0, 0));

  pixels.setPixelColor(21, pixels.Color(50, 0, 0));
  pixels.setPixelColor(22, pixels.Color(50, 0, 0));
  pixels.setPixelColor(23, pixels.Color(50, 0, 0));
  pixels.setPixelColor(24, pixels.Color(50, 0, 0));
  pixels.setPixelColor(25, pixels.Color(50, 0, 0));
  pixels.setPixelColor(26, pixels.Color(40, 10, 0));
  pixels.setPixelColor(27, pixels.Color(50, 0, 0));
  pixels.setPixelColor(28, pixels.Color(50, 0, 0));
  pixels.setPixelColor(29, pixels.Color(50, 0, 0));
  pixels.setPixelColor(30, pixels.Color(50, 0, 0));
  pixels.setPixelColor(31, pixels.Color(50, 0, 0));
  pixels.setPixelColor(32, pixels.Color(50, 0, 0));
  pixels.setPixelColor(33, pixels.Color(50, 0, 0));
  pixels.setPixelColor(34, pixels.Color(50, 0, 0));
  pixels.setPixelColor(35, pixels.Color(50, 0, 0));
  pixels.setPixelColor(36, pixels.Color(50, 0, 0));
  pixels.setPixelColor(37, pixels.Color(40, 10, 0));
  pixels.setPixelColor(38, pixels.Color(50, 0, 0));
  pixels.setPixelColor(39, pixels.Color(50, 0, 0));
  pixels.setPixelColor(40, pixels.Color(50, 0, 0));
  pixels.setPixelColor(41, pixels.Color(50, 0, 0));
  pixels.setPixelColor(42, pixels.Color(50, 0, 0));
  pixels.setPixelColor(43, pixels.Color(50, 0, 0));
  pixels.setPixelColor(44, pixels.Color(50, 0, 0));
  pixels.setPixelColor(45, pixels.Color(50, 0, 0));
  pixels.setPixelColor(46, pixels.Color(50, 0, 0));
  pixels.setPixelColor(47, pixels.Color(50, 0, 0));
  pixels.setPixelColor(48, pixels.Color(50, 0, 0));
  pixels.setPixelColor(49, pixels.Color(50, 0, 0));
  pixels.setPixelColor(50, pixels.Color(50, 0, 0));
  pixels.setPixelColor(51, pixels.Color(50, 0, 0));
  pixels.setPixelColor(52, pixels.Color(50, 0, 0));
  pixels.setPixelColor(53, pixels.Color(50, 0, 0));
  pixels.setPixelColor(54, pixels.Color(50, 0, 0));
  pixels.setPixelColor(55, pixels.Color(50, 0, 0));
  pixels.setPixelColor(56, pixels.Color(50, 0, 0));
  pixels.setPixelColor(57, pixels.Color(50, 0, 0));
  pixels.setPixelColor(58, pixels.Color(50, 0, 0));
  pixels.setPixelColor(59, pixels.Color(50, 0, 0));
  pixels.setPixelColor(60, pixels.Color(50, 0, 0));
  pixels.setPixelColor(61, pixels.Color(50, 0, 0));
  pixels.setPixelColor(62, pixels.Color(50, 0, 0));
  pixels.setPixelColor(63, pixels.Color(50, 0, 0));
  pixels.setPixelColor(64, pixels.Color(50, 0, 0));
  pixels.setPixelColor(0, pixels.Color(50, 0, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
}
void superHot () {
  pixels.setPixelColor(1, pixels.Color(50, 0, 0));
  pixels.setPixelColor(2, pixels.Color(50, 0, 0));
  pixels.setPixelColor(3, pixels.Color(50, 0, 0));
  pixels.setPixelColor(4, pixels.Color(50, 0, 0));
  pixels.setPixelColor(5, pixels.Color(50, 0, 0));
  pixels.setPixelColor(6, pixels.Color(50, 0, 0));
  pixels.setPixelColor(7, pixels.Color(50, 0, 0));
  pixels.setPixelColor(8, pixels.Color(50, 0, 0));
  pixels.setPixelColor(9, pixels.Color(50, 50, 50));
  pixels.setPixelColor(10, pixels.Color(50, 50, 50));
  pixels.setPixelColor(11, pixels.Color(50, 50, 50));
  pixels.setPixelColor(12, pixels.Color(50, 50, 50));
  pixels.setPixelColor(13, pixels.Color(50, 50, 50));
  pixels.setPixelColor(14, pixels.Color(50, 0, 0));
  pixels.setPixelColor(15, pixels.Color(50, 0, 0));
  pixels.setPixelColor(16, pixels.Color(50, 0, 0));
  pixels.setPixelColor(17, pixels.Color(50, 0, 0));
  pixels.setPixelColor(18, pixels.Color(50, 0, 0));
  pixels.setPixelColor(19, pixels.Color(50, 0, 0));
  pixels.setPixelColor(20, pixels.Color(50, 0, 0));

  pixels.setPixelColor(21, pixels.Color(50, 0, 0));
  pixels.setPixelColor(22, pixels.Color(50, 50, 50));
  pixels.setPixelColor(23, pixels.Color(50, 0, 0));
  pixels.setPixelColor(24, pixels.Color(50, 0, 0));
  pixels.setPixelColor(25, pixels.Color(50, 0, 0));
  pixels.setPixelColor(26, pixels.Color(50, 50, 50));
  pixels.setPixelColor(27, pixels.Color(50, 50, 50));
  pixels.setPixelColor(28, pixels.Color(50, 50, 50));
  pixels.setPixelColor(29, pixels.Color(50, 50, 50));
  pixels.setPixelColor(30, pixels.Color(50, 0, 0));
  pixels.setPixelColor(31, pixels.Color(50, 0, 0));
  pixels.setPixelColor(32, pixels.Color(50, 0, 0));
  pixels.setPixelColor(33, pixels.Color(50, 0, 0));
  pixels.setPixelColor(34, pixels.Color(50, 50, 50));
  pixels.setPixelColor(35, pixels.Color(50, 50, 50));
  pixels.setPixelColor(36, pixels.Color(50, 50, 50));
  pixels.setPixelColor(37, pixels.Color(50, 50, 50));
  pixels.setPixelColor(38, pixels.Color(50, 0, 0));
  pixels.setPixelColor(39, pixels.Color(50, 0, 0));
  pixels.setPixelColor(40, pixels.Color(50, 0, 0));
  pixels.setPixelColor(41, pixels.Color(50, 50, 50));
  pixels.setPixelColor(42, pixels.Color(50, 50, 50));
  pixels.setPixelColor(43, pixels.Color(50, 50, 50));
  pixels.setPixelColor(44, pixels.Color(50, 50, 50));
  pixels.setPixelColor(45, pixels.Color(50, 50, 50));
  pixels.setPixelColor(46, pixels.Color(50, 0, 0));
  pixels.setPixelColor(47, pixels.Color(50, 0, 0));
  pixels.setPixelColor(48, pixels.Color(50, 0, 0));
  pixels.setPixelColor(49, pixels.Color(50, 0, 0));
  pixels.setPixelColor(50, pixels.Color(50, 0, 0));
  pixels.setPixelColor(51, pixels.Color(50, 0, 0));
  pixels.setPixelColor(52, pixels.Color(50, 50, 50));
  pixels.setPixelColor(53, pixels.Color(50, 0, 0));
  pixels.setPixelColor(54, pixels.Color(50, 0, 0));
  pixels.setPixelColor(55, pixels.Color(50, 0, 0));
  pixels.setPixelColor(56, pixels.Color(50, 0, 0));
  pixels.setPixelColor(57, pixels.Color(50, 50, 50));
  pixels.setPixelColor(58, pixels.Color(50, 50, 50));
  pixels.setPixelColor(59, pixels.Color(50, 50, 50));
  pixels.setPixelColor(60, pixels.Color(50, 50, 50));
  pixels.setPixelColor(61, pixels.Color(50, 50, 50));
  pixels.setPixelColor(62, pixels.Color(50, 0, 0));
  pixels.setPixelColor(63, pixels.Color(50, 0, 0));
  pixels.setPixelColor(64, pixels.Color(50, 0, 0));
  pixels.setPixelColor(0, pixels.Color(50, 0, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void cold () {
  int R = 0;
  int G = 0;
  int B = 60;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B));
  pixels.setPixelColor(4, pixels.Color(50, 50, 50));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(R, G, B));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(R, G, B));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(50, 50, 50));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B));
  pixels.setPixelColor(18, pixels.Color(R, G, B));
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(50, 50, 50));

  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B));
  pixels.setPixelColor(25, pixels.Color(50, 50, 0));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(50, 50, 0));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(50, 50, 0));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(50, 50, 0));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(50, 50, 0));
  pixels.setPixelColor(42, pixels.Color(50, 50, 0));
  pixels.setPixelColor(43, pixels.Color(50, 50, 0));
  pixels.setPixelColor(44, pixels.Color(50, 50, 0));
  pixels.setPixelColor(45, pixels.Color(50, 50, 0));
  pixels.setPixelColor(46, pixels.Color(50, 50, 0));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void warm () {
  int R = 40;
  int G = 10;
  int B = 0;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B));
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(50, 50, 50));
  pixels.setPixelColor(7, pixels.Color(50, 50, 50));
  pixels.setPixelColor(8, pixels.Color(50, 50, 50));
  pixels.setPixelColor(9, pixels.Color(50, 50, 50));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(50, 50, 50));
  pixels.setPixelColor(17, pixels.Color(50, 50, 50));
  pixels.setPixelColor(18, pixels.Color(50, 50, 50));
  pixels.setPixelColor(19, pixels.Color(50, 50, 50));
  pixels.setPixelColor(20, pixels.Color(50, 50, 50));

  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B));
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(50, 50, 50));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(50, 50, 50));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B));
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(50, 50, 50));
  pixels.setPixelColor(48, pixels.Color(50, 50, 50));
  pixels.setPixelColor(49, pixels.Color(50, 50, 50));
  pixels.setPixelColor(50, pixels.Color(50, 50, 50));
  pixels.setPixelColor(51, pixels.Color(50, 50, 50));
  pixels.setPixelColor(52, pixels.Color(50, 50, 50));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void lesswarm () {
  int R = 60;
  int G = 10;
  int B = 0;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B));
  pixels.setPixelColor(4, pixels.Color(0, 0, 50));
  pixels.setPixelColor(5, pixels.Color(0, 0, 50));
  pixels.setPixelColor(6, pixels.Color(0, 0, 50));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(0, 0, 50));
  pixels.setPixelColor(10, pixels.Color(0, 0, 50));
  pixels.setPixelColor(11, pixels.Color(0, 0, 50));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B));
  pixels.setPixelColor(18, pixels.Color(R, G, B));
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));

  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B));
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(0, 0, 50));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(R, G, B));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(0, 0, 50));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B));
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void chill () {
  int R = 0;
  int G = 30;
  int B = 50;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B));
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(50, 50, 0));
  pixels.setPixelColor(7, pixels.Color(50, 50, 0));
  pixels.setPixelColor(8, pixels.Color(50, 50, 0));
  pixels.setPixelColor(9, pixels.Color(50, 50, 0));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B));
  pixels.setPixelColor(18, pixels.Color(R, G, B));
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));

  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B));
  pixels.setPixelColor(25, pixels.Color(50, 50, 0));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(50, 50, 0));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(50, 50, 0));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(50, 50, 0));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(50, 50, 0));
  pixels.setPixelColor(42, pixels.Color(50, 50, 0));
  pixels.setPixelColor(43, pixels.Color(50, 50, 0));
  pixels.setPixelColor(44, pixels.Color(50, 50, 0));
  pixels.setPixelColor(45, pixels.Color(50, 50, 0));
  pixels.setPixelColor(46, pixels.Color(50, 50, 0));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void waveR () {
  int R = 50;
  int G = 0;
  int B = 0;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B));
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(R, G, B));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(R, G, B));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(18, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));
  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(R, G, B));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void waveB () {
  int R = 0;
  int G = 0;
  int B = 50;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(R, G, B));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(R, G, B));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(18, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));
  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(R, G, B));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void waveG () {
  int R = 0;
  int G = 50;
  int B = 0;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(R, G, B));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(R, G, B));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(18, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));
  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(R, G, B));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void waveRB () {
  int R = 50;
  int G = 0;
  int B = 50;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(R, G, B));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(R, G, B));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(18, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));
  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(R, G, B));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void waveRG () {
  int R = 50;
  int G = 50;
  int B = 0;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(R, G, B));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(R, G, B));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(18, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));
  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(R, G, B));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void waveGB () {
  int R = 0;
  int G = 50;
  int B = 50;
  pixels.setPixelColor(1, pixels.Color(R, G, B));
  pixels.setPixelColor(2, pixels.Color(R, G, B));
  pixels.setPixelColor(3, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(4, pixels.Color(R, G, B));
  pixels.setPixelColor(5, pixels.Color(R, G, B));
  pixels.setPixelColor(6, pixels.Color(R, G, B));
  pixels.setPixelColor(7, pixels.Color(R, G, B));
  pixels.setPixelColor(8, pixels.Color(R, G, B));
  pixels.setPixelColor(9, pixels.Color(R, G, B));
  pixels.setPixelColor(10, pixels.Color(R, G, B));
  pixels.setPixelColor(11, pixels.Color(R, G, B));
  pixels.setPixelColor(12, pixels.Color(R, G, B));
  pixels.setPixelColor(13, pixels.Color(R, G, B));
  pixels.setPixelColor(14, pixels.Color(R, G, B));
  pixels.setPixelColor(15, pixels.Color(R, G, B));
  pixels.setPixelColor(16, pixels.Color(R, G, B));
  pixels.setPixelColor(17, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(18, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(19, pixels.Color(R, G, B));
  pixels.setPixelColor(20, pixels.Color(R, G, B));
  pixels.setPixelColor(21, pixels.Color(R, G, B));
  pixels.setPixelColor(22, pixels.Color(R, G, B));
  pixels.setPixelColor(23, pixels.Color(R, G, B));
  pixels.setPixelColor(24, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(25, pixels.Color(R, G, B));
  pixels.setPixelColor(26, pixels.Color(R, G, B));
  pixels.setPixelColor(27, pixels.Color(R, G, B));
  pixels.setPixelColor(28, pixels.Color(R, G, B));
  pixels.setPixelColor(29, pixels.Color(R, G, B));
  pixels.setPixelColor(30, pixels.Color(R, G, B));
  pixels.setPixelColor(31, pixels.Color(R, G, B));
  pixels.setPixelColor(32, pixels.Color(R, G, B));
  pixels.setPixelColor(33, pixels.Color(R, G, B));
  pixels.setPixelColor(34, pixels.Color(R, G, B));
  pixels.setPixelColor(35, pixels.Color(R, G, B));
  pixels.setPixelColor(36, pixels.Color(R, G, B));
  pixels.setPixelColor(37, pixels.Color(R, G, B));
  pixels.setPixelColor(38, pixels.Color(R, G, B));
  pixels.setPixelColor(39, pixels.Color(R, G, B));
  pixels.setPixelColor(40, pixels.Color(R, G, B));
  pixels.setPixelColor(41, pixels.Color(R, G, B));
  pixels.setPixelColor(42, pixels.Color(R, G, B));
  pixels.setPixelColor(43, pixels.Color(R, G, B));
  pixels.setPixelColor(44, pixels.Color(R, G, B));
  pixels.setPixelColor(45, pixels.Color(R, G, B)) ;
  pixels.setPixelColor(46, pixels.Color(R, G, B));
  pixels.setPixelColor(47, pixels.Color(R, G, B));
  pixels.setPixelColor(48, pixels.Color(R, G, B));
  pixels.setPixelColor(49, pixels.Color(R, G, B));
  pixels.setPixelColor(50, pixels.Color(R, G, B));
  pixels.setPixelColor(51, pixels.Color(R, G, B));
  pixels.setPixelColor(52, pixels.Color(R, G, B));
  pixels.setPixelColor(53, pixels.Color(R, G, B));
  pixels.setPixelColor(54, pixels.Color(R, G, B));
  pixels.setPixelColor(55, pixels.Color(R, G, B));
  pixels.setPixelColor(56, pixels.Color(R, G, B));
  pixels.setPixelColor(57, pixels.Color(R, G, B));
  pixels.setPixelColor(58, pixels.Color(R, G, B));
  pixels.setPixelColor(59, pixels.Color(R, G, B));
  pixels.setPixelColor(60, pixels.Color(R, G, B));
  pixels.setPixelColor(61, pixels.Color(R, G, B));
  pixels.setPixelColor(62, pixels.Color(R, G, B));
  pixels.setPixelColor(63, pixels.Color(R, G, B));
  pixels.setPixelColor(64, pixels.Color(R, G, B));
  pixels.setPixelColor(0, pixels.Color(R, G, B));
  pixels.show();   // Send the updated pixel colors to the hardware.
}

void program1 () {

  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.print(F("Temperature: "));
  Serial.print(event.temperature);
  Serial.println(F("°C"));
  int temp = event.temperature;

  if (buttonState1 == LOW) {
    if (temp >= 76 && temp <= 87) //if temperature is 100 degrees
    {
      dht.temperature().getEvent(&event);
      hot ();
      pixels.clear();
    }
    else if (temp >= 65 && temp <= 75) {
      dht.temperature().getEvent(&event);
      lesshot () ;
      pixels.clear();
    }
    else if (temp >= 53 && temp <= 64) {
      dht.temperature().getEvent(&event);
      lesserhot () ;
      pixels.clear();
    }
    else if (temp <= 26) {
      dht.temperature().getEvent(&event);
      cold () ;
      pixels.clear();
    }
    else if (temp >= 40 && temp < 50) {
      dht.temperature().getEvent(&event);
      warm () ;
      pixels.clear();
    }
    else if (temp >= 31 && temp < 39) {
      dht.temperature().getEvent(&event);
      lesswarm () ;
      pixels.clear();
    }
    else if (temp >= 27 && temp <= 30) {
      dht.temperature().getEvent(&event);
      chill () ;
      pixels.clear();
    }

    else if (temp >= 88) {
      dht.temperature().getEvent(&event);
      superHot() ;
      delay(500);
      pixels.clear();
      delay(500);
    }
    return;
  }
  program1();
}
// WAVE MODE
void program2() {
  waveR () ;
  delay(1000);
  pixels.clear();
  delay(500);
}
void program3() {
  waveG () ;
  delay(100);
  pixels.clear();
  delay(500);
}
void program4() {
  waveB () ;
  delay(1000);
  pixels.clear();
  delay(500);
}


void loop() {
  buttonState1 = digitalRead (5);

  if (buttonState1 == LOW)
  {
    program1();
  }
  button.loop(); // MUST call the loop() function first

  count = button.getCount();

  if (count != lastCount) {
    Serial.println(count);

    int countIn3 = count % 3 + 1;

    switch (countIn3) {
      case 1:
        // TO DO TASK 1
        program2();
        break;

      case 2:
        // TO DO TASK 2
        program3();
        break;

      case 3:
        // TO DO TASK 3
        program4();
        break;
    }

    lastCount = count;
  }
}
