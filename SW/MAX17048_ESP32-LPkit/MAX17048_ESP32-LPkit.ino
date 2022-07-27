/*
 * This example code for Fuel Gauge - MAX17048 module
 * is used with ESP32 LPkit board.
 * ESP32-LPkit reads temperature and humidity from SHT40 sensor 
 * and sends every second through UART
 * We are not using ALERT pin in ths code
 * 
 * SDA - GPIO21
 * SCL - GPIO22
 *
 * Made by (c) laskakit.cz 2022
 *
 * Libraries
 * https://github.com/hideakitai/MAX17048
 */


#include <SPI.h>
#include <Wire.h>
#include "MAX17048.h" // https://github.com/hideakitai/MAX17048

MAX17048 pwr_mgmt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  Wire.begin (21, 22); // for ESP32 + uŠup
  pwr_mgmt.attatch(Wire); //připojí čip MAX17048 k desce
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println((String)"VCELL ADC : "+pwr_mgmt.adc()); //Vypíše hodnotu na ADC pinu 
  Serial.println((String)"VCELL V   : "+pwr_mgmt.voltage()+"V"); //Vypíše napětí na baterii
  Serial.println((String)"VCELL SOC : "+pwr_mgmt.percent()+" \%"); //Vypíše přibližné nabití baterie
  Serial.println((String)"VCELL SOC : "+pwr_mgmt.accuratePercent()+" \%"); //Vypíše přesné nabití baterie 
  Serial.println();
  delay(1000);
}
