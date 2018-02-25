
#include "wifi_connect.h"
#include "heater_server.h"
#include "heater_comm.h"
#include "led.h"

WifiConnect wifiConnect("heater01");
HeaterComm communication;
HeaterServer server(&communication);
Led led(D4);


void setup() {
  Serial.begin(115200);
  
  if (!wifiConnect.startWPSPBC()) {
    Serial.printf("Could not connect to the local wifi\n");
  } else {
    Serial.printf("Connected to the network\n");
  }

}

void loop() {
  server.runApi();
}
