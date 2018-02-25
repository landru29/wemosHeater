#include "heater_server.h"
#include <ESP8266WebServer.h>


ESP8266WebServer _server_(80);

HeaterComm* HeaterServer::io = 0;


HeaterServer::HeaterServer(HeaterComm* comm) {
  _server_.on("/status", HTTP_GET, HeaterServer::handleGetRoot);
  _server_.on("/status", HTTP_POST, HeaterServer::handlePostRoot);
  _server_.begin();
  HeaterServer::io = comm;
}

String HeaterServer::getStatusStr() {
  switch (HeaterServer::io->status) {
    case ZERO:
      return String("zero");
    case POSITIVE:
      return String("positive");
    case NEGATIVE:
      return String("negative");
    case ALTERNATIVE:
      return String("alternative");
    default:
      return String("unknown");
  }
}

void HeaterServer::handleGetRoot() {

  String content = "{";
  content += String("\"status\":\"" + HeaterServer::getStatusStr() + "\"");
  content += "}";

  _server_.send(200, "application/json", content);
}

void HeaterServer::handlePostRoot() {

  if (_server_.hasArg("plain")== false){ //Check if body received
    String errorContent = "{";
    errorContent += String("\"status\":\"Empty body\"");
    errorContent += "}";
 
    _server_.send(400, "application/json", errorContent);
    return;
 
 }
  
  String body=_server_.arg("plain");
 
  if (body == "zero") {
    HeaterServer::io->setStatus(ZERO);
  }

  if (body == "positive") {
    HeaterServer::io->setStatus(POSITIVE);
  }

  if (body == "negative") {
    HeaterServer::io->setStatus(NEGATIVE);
  }

  if (body == "alternative") {
    HeaterServer::io->setStatus(ALTERNATIVE);
  }

 
  String content = "{";
  content += String("\"status\":\"" + HeaterServer::getStatusStr() + "\",");
  content += String("\"command\":\"" + body + "\"");
  content += "}";

  _server_.send(200, "application/json", content);
}

void HeaterServer::runApi() {
  _server_.handleClient();
}
