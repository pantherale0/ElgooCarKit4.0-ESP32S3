#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <Arduino.h>
#include "esp_camera.h"
#include "RobotSettingManager.h"

class CameraManager
{
public:
    CameraManager(RobotSettingManager *);
    void changeResolution(int value);
    void changeQuality(int value);
    void changeContrast(int value);
    void changeBrightness(int value);
    void changeSaturation(int value);
    int getQuality();
    int getResolution();
    int getContrast();
    int getBrightness();
    int getSaturation();

private:
    void init();
    RobotSettingManager *robotSettingManager;
    int quality;
    int resolution;
    int contrast;
    int brightness;
    int saturation;
};

#endif
