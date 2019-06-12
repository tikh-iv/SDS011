// On ESP32 with custom defined Serial Port
#include <SDS011.h>

#define RXD2 13
#define TXD2 12

float p10, p25;
int error;

SDS011 sdsPPM;

HardwareSerial SerialSDS(2);

void setup() {
  Serial.begin(115200);
  Serial.println("Serial TX is on pin: "+String(TXD2));
  Serial.println("Serial RX is on pin: "+String(RXD2));
  sdsPPM.begin(&SerialSDS, RXD2, TXD2);
}

void loop() {
  Serial.println("Starting Up the SDS011 Sensor");
  sdsPPM.wakeup();
  delay(40000);
  error = sdsPPM.read(&p25, &p10);
  if (!error) {
    Serial.print("PM2.5: " + String(p25) + ", ");
    Serial.println("PM10:  " + String(p10));
  }
  Serial.println("Putting to Sleep the SDS011 Sensor");
  sdsPPM.sleep();
  delay(120000);
}
