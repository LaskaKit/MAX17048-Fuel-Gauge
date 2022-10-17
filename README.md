![LaskaKit Fuel gauge MAX17048](https://github.com/LaskaKit/MAX17048-Fuel-Gauge/blob/main/img/1.jpg)

# 1S fuel Gauge with ultra lowpower consumption - MAX17048

To know, when the battery inside of your device is almost empty is very useful information. In case when you leave to nice vacation and during the vacation you get the message that your device is not responding. 
Of course, you can measure the battery voltage, but it is not so accurate. The better way is to use Fuel gauge. What is it?

Fuel gauge is the integrated circuit what is able to measure battery voltage and thanks to calculation inside of the IC is able to estimate the real battery voltage and also the capacitance of that. 
How to use [LaskaKit Fuel Gauge MAX17048](https://www.laskakit.cz/laskakit-fuel-gauge-max17048-bateriovy-meric/) in your project is super easy. Just connect the battery to module (JST-PH connector) and your device to second JST-PH connector. The communication with Fuel Gauge is going through I2C and this module includes two μŠup connectors. So you can easily extend the project by another module/sensor with μŠup connector, for example [SHT40 (temperature/humidity sensor)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/) or [SCD41 (temperature/humidity/CO2 sensor)](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/).
And this modules and sensors you can connector with main board as [LaskaKit ESP32-LPKit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/?variantId=10488) or [LaskaKit microESP](https://www.laskakit.cz/laskakit-microesp/).

And how is it working in your code? Thanks to [this MAX17048 Arduino library](https://github.com/hideakitai/MAX17048), made by Hideaki Tai, it is super easy. Look.
```
#include "MAX17048.h"

MAX17048 pwr_mgmt;

void setup()
{
    Serial.begin(115200);
    Wire.begin();
    pwr_mgmt.attatch(Wire);
}

void loop()
{
    Serial.print("VCELL ADC : ");
    Serial.println(pwr_mgmt.adc());
    Serial.print("VCELL V   : ");
    Serial.println(pwr_mgmt.voltage());
    Serial.print("VCELL SOC : ");
    Serial.print(pwr_mgmt.percent());
    Serial.println(" \%");
    Serial.print("VCELL SOC : ");
    Serial.print(pwr_mgmt.accuratePercent());
    Serial.println(" \%");
    Serial.println();
    delay(1000);
}
```

## Electrical specification of MAX17048
Supply voltage: 2.5 - 4.5V</br>
Own current during hibernation mode: 3uA</br>
Own current during normal mode: 23uA</br>
ADC sampling period: 250ms (normal mode) or 45s (hibernation mode)</br>
Voltage error: +-7.5mV/cell</br>

The Fuel Gauge module you can buy on https://www.laskakit.cz/laskakit-fuel-gauge-max17048-bateriovy-meric/
