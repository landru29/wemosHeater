#ifndef __HEATER_SERVER__H__
#define __HEATER_SERVER__H__
#include "heater_comm.h"
#include <ESP8266WiFi.h>


class HeaterServer {
  public:
    HeaterServer(HeaterComm* comm);
    void runApi();
    static void handleGetRoot();
    static void handlePostRoot();
    static HeaterComm* io;
    static String getStatusStr();
};

#endif
