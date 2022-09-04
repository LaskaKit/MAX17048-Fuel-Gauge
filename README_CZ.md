![LaskaKit Fuel gauge MAX17048](https://github.com/LaskaKit/MAX17048-Fuel-Gauge/blob/main/img/1.jpg)

# 1S fuel Gauge s ultranízkou vlastní spotřebou - MAX17048

Vědět, kdy se vybíjí akumulátor v zařízení je fakt hodně důležitý. Když odjedeš na dovolenou, zamrzí, když se tvoje zařízení vybije během ní. Samozřejmě můžeš měřit napětí akumulátoru, ale to je vzhledem k charakteristice baterií/akumulátorů nepřesné - orientační.

Fuel gauge je obvod, který měří napětí baterie/akumulátoru a díky přepočtu uvnitř čipu je schopen nejen reportovat napětí na akumulátoru, ale také jeho kapacitu.
Prace s takovým obvodem je jednoduchá a díky našemu modulu ještě jednodušší - prostě jen připojíš akumulátor do [LaskaKit Fuel Gauge MAX17048](https://www.laskakit.cz/laskakit-fuel-gauge-max17048-bateriovy-meric/) a z něj do napájecího konektoru tvého zařízení (oba jsou JST-PH). Data si vyčteš pomocí I2C sběrnici, které je dostupný na μŠup konektoru. A jsou tam dva, abys k tomu stejnému modulu mohl propojit další I2C modul - třeba [SHT40 (čidlo teploty/vlhkosti)](https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/) nebo [SCD41 (čidlo teploty/vlhkosti/CO2)](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/).
Takhle jednoduše propojíš tento modul s fuel gauge obvodem třeba s [LaskaKit ESP32-LPKit](https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/?variantId=10488) nebo [LaskaKit microESP](https://www.laskakit.cz/laskakit-microesp/).

A jak se s takovým modulem komunikuje? Existuje [knihovna MAX17048](https://github.com/hideakitai/MAX17048), kterou napsal Hideaki Tai a práce s ní je opravdu jednoduchá. 
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
Modul s Fuel Gauge můžeš koupit u nás na e-shopu https://www.laskakit.cz/laskakit-fuel-gauge-max17048-bateriovy-meric/
