# ESP8266 Zabbix Temperature sensor

## ------- Setting up your ESP SIDE -------
### 1) First make sure everything is ready for ESP8266
Try some tutorials like this:  
https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/


### 2) Install missing Arduino libraries
Sketch -> Include Library -> Manage Libraries...  
Install library "DallasTemperature"  

<img src="img/DS18B20_lib.png" width="500">  


### 3) Set your WiFi and Zabbix information

ZABBIXAGHOST is ...  
ZABBIX_KEY is ...  

### 4) Connecting DS18B20 physically
  
  
  


## ------- Setting up your Zabbix SIDE -------

### 1) Now lets add host to Zabbix
Click on Configuration->Hosts->Create host  
Then set up required fields:  
  
<img src="img/Zabbix_1.png" width="1000">  
  
Hostname - create name for your host  
Groups - set group you want or create new one  
Agent interfaces - (IP address and Port).  
  
And Click add  
  
<img src="img/Zabbix_2.png" width="1000">  
  
### 2) Add item to host
Now when we have host we need to add item that we want to get from it. In our case - temperature.  
  
Select created host Configuration->Hosts-> YOUR_HOST  
if you cannot see your host select group at top-right  
  
Click Items->Create item  
  
<img src="img/Zabbix_3.png" width="1000">  
  
Fill required fields:  
  
Name - ZABBIX_KEY  
Type - Zabbix trapper  
Type of information - Numeric (float)  
*optional Units - °C or °F  
  
  
### 3) View data ;)
Host are ready to use. Now we can view data in widgets  
  
Open your dashboard (Or create new one)-> add widget -> graph  
<img src="img/Zabbix_4.png" width="1000">  
  
set dataset:  
host pettern - host created at step 1.  
item pattern- item created at step 2.  
  
  

## Credits
[zaphodus](https://github.com/zaphodus/ESP8266ZabbixSender) for Zabbix sender library  
[Eimantas Rebzdys](https://github.com/EimantasRebzdys) for Helping configure Zabbix  
