/*
 * This example code for Fuel Gauge - MAX17048 module with OLED display with SH1106 driver
 * is used with ESP32 LPkit board.
 * ESP32-LPkit battery data and displaying them on the OLED.
 * We are not using ALERT pin in ths code
 * 
 * https://github.com/LaskaKit/MAX17048-Fuel-Gauge
 * 
 * SDA - GPIO21
 * SCL - GPIO22
 *
 * Made by (c) laskakit.cz 2022
 *
 * Libraries
 * https://github.com/hideakitai/MAX17048
 * https://github.com/adafruit/Adafruit_SH110X
 */


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h> //Nutné stáhnout knihovnu - https://github.com/adafruit/Adafruit_SH110X
#include "MAX17048.h" //Nutné stáhnout knihovnu MAX17048 - https://github.com/hideakitai/MAX17048

MAX17048 pwr_mgmt;

#define i2c_Address 0x3c //Na této adrese je displej, pokud nebude fungoval zkuste vyměnit za 0x3d
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1); //Přiřadí displej, tloušťku a výšku

void setup()
{
    Serial.begin(115200);
    Wire.begin (21, 22);                // for ESP32 + uŠup
    pwr_mgmt.attatch(Wire);             //připojí čip MAX17048 k desce
    delay(250);
    display.begin(i2c_Address, true);   // Address 0x3C default
    display.clearDisplay();
    display.setTextColor(SH110X_WHITE); //Nastaví barvu displeje
    display.setTextSize(1);             //Nastaví velikost písma
    
}

void loop()
{
  
   display.setCursor(0,0);                                                      //Nastaví kurzor na základní pozici. 
   display.println((String)"ADC:"+pwr_mgmt.adc());                              //Vypíše na display hodnotu naměřenou na ADC pinu
   display.println((String)"Napeti:"+pwr_mgmt.voltage()+"V");                   //Vypíše na display napětí baterie
   display.println((String)"Baterie:"+pwr_mgmt.percent()+" \%");                //Vypíše na display příblyžné nabití baterie v procentech
   display.println((String)"Baterie presne:"+pwr_mgmt.accuratePercent()+" \%"); //Vypíše na display přesné nabití baterie v procentech
   display.display(); 
   Serial.println((String)"VCELL ADC : "+pwr_mgmt.adc());
   Serial.println((String)"VCELL V   : "+pwr_mgmt.voltage()+"V");
   Serial.println((String)"VCELL SOC : "+pwr_mgmt.percent()+" \%");
   Serial.println((String)"VCELL SOC : "+pwr_mgmt.accuratePercent()+" \%");
   Serial.println();
   delay(500);
   display.clearDisplay();
}
