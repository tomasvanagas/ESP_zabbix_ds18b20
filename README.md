# ESP8266 Zabbix Temperature sensor

## ------- Setting up your ESP SIDE -------
### 1) First make sure everything is ready for ESP8266
Try some tutorials like this:  
https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/


### 2) Install missing Arduino libraries
Sketch -> Include Library -> Manage Libraries...  

Install library "OneWire"  

<img src="img/01_Library.png" width="500"> 

Install library "DallasTemperature"  

<img src="img/02_Library.png" width="500">  




### 3) Set your WiFi and Zabbix information

ZABBIXAGHOST is Hostname in Zabbix system e.g.: ESP  
ZABBIX_KEY is Key in Zabbix system e.g.: ServerRoom

### 4) Connecting DS18B20 physically
  
  
  
  
  
[SetUp Zabbix](https://github.com/tomasvanagas/ESP_zabbix_ds18b20/blob/master/zabbix_README.md)  
  
  
  
  
## Credits
[zaphodus](https://github.com/zaphodus/ESP8266ZabbixSender) for Zabbix sender library  
[Eimantas Rebzdys](https://github.com/EimantasRebzdys) for Helping configure Zabbix  
