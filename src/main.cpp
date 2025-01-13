#include <Arduino.h>
#include "TimeManager.h"
#include "WifiManager.h"
#include "HttpServerManager.h"
#include "SerialComManager.h"
#include "CameraManager.h"
#include "RobotSettingManager.h"
#include "RobotStateManager.h"

#define RXD2 3
#define TXD2 40

TimeManager *timeManager;
WifiManager *wifiManager;
HttpServerManager *httpServerManager;
SerialComManager *serialComManager;
CameraManager *cameraManager;
RobotSettingManager *robotSettingManager;
RobotStateManager *robotStateManager;

void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); // Nécessaire pour que le WIFI accepte de se connecter quand l'ESP et l'arduino sont connectés ensemble ???
  Serial.println("Init Start");
  robotSettingManager = new RobotSettingManager();
  timeManager = new TimeManager();
  Serial.println("Time Manager started");
  wifiManager = new WifiManager(robotSettingManager);
  Serial.println("Wifi Manager started");
  cameraManager = new CameraManager(robotSettingManager);
  robotStateManager = new RobotStateManager(cameraManager, robotSettingManager, timeManager);
  Serial.println("Robot state manager started");
  httpServerManager = new HttpServerManager(robotStateManager);
  Serial.println("HTTP started");
  serialComManager = new SerialComManager(timeManager, httpServerManager, wifiManager, robotStateManager);
  Serial.println("COM Manager started");
}

void loop()
{
  timeManager->updateLoopTime();
  serialComManager->receiveSerialData();
}
