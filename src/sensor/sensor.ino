// Copyright (c) 2022 Tomas Vanagas, Eimantas Rebzdys
// Copyright (c) 2022 Vilnius university, Kaunas faculty
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "ESP8266ZabbixSender.h"
#include <Base64.h>
#include <OneWire.h>
#include <DallasTemperature.h>

ESP8266ZabbixSender zSender;

////////////////////////////////////// USER SETTINGS //////////////////////////////////////

// ******** Example ********
#define SERVERADDR 192, 168, 0, 123 // IP Address example 192.168.0.123
#define ZABBIXPORT 10051
#define ZABBIXAGHOST "ESP"
#define ZABBIX_KEY "ServerRoom"
String espHostname = "ESP-ServerRoom";
// WiFi settings
String ssid = "AndroidAP";
String pass = "12345678";

///////////////////////////////////////////////////////////////////////////////////////////




// DS18B20
OneWire oneWire(2); // GPIO2 or D4 pin on ESP device
DallasTemperature DS18B20(&oneWire);


// WiFi connectivity checker
boolean checkConnection() {
  Serial.println("Checking Wifi");
  while (true) {
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("Wifi connected!");
      return (true);
    }
    delay(500);
    Serial.print(".");
  }
  Serial.println("Timed out.");
  return false;
}

void setup() {

  // Initialize terminal
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("Initializing Zabbix Temperature sensor...");

  // Configure WiFi
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  WiFi.hostname(espHostname.c_str());
  WiFi.begin(ssid.c_str(), pass.c_str());
  
  // Wait for connectivity
  while (!checkConnection());

  // Initialize Zabbix sender
  zSender.Init(IPAddress(SERVERADDR), ZABBIXPORT, ZABBIXAGHOST);
}

void loop() {
  
  // Get temperature from DS18B20
  DS18B20.requestTemperatures(); 
  float temp = DS18B20.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.println(temp);

  // Check connectivity
  checkConnection();

  // If temperature is good - send it to Zabbix
  if (! (temp == 85.0 || temp == (-127.0))) {
    zSender.ClearItem();              
    zSender.AddItem(ZABBIX_KEY, temp); 
    if (zSender.Send() == EXIT_SUCCESS) {
      Serial.println("ZABBIX SEND: OK");
    } else {
      Serial.println("ZABBIX SEND: Not Good");
    }
  }

  
  delay(1000); 
}
