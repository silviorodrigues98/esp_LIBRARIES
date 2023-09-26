#ifndef MY_SERIAL_DEBUG_H
#define MY_SERIAL_DEBUG_H

#include <Arduino.h>

enum DebugLevel
{
    DEBUG_NONE = 0,
    DEBUG_ERROR = 1 << 0,  // 1
    DEBUG_WARN = 1 << 1,   // 2
    DEBUG_INFO = 1 << 2,   // 4
    DEBUG_DEBUG = 1 << 3,  // 8
    DEBUG_VERBOSE = 1 << 4 // 16
};

class MySerialDebug
{
public:
    MySerialDebug() : level(DEBUG_NONE) {}

    void begin(long speed, int lvl)
    {
        Serial.begin(speed);
        while (!Serial)
        {
            ; // wait for serial port to connect. Needed for native USB port only
        }
        level = lvl;
    }

    void printError(const char *msg)
    {
        if (level & DEBUG_ERROR)
        {
            Serial.print("[ERROR] ");
            Serial.println(msg);
        }
    }

    void printWarn(const char *msg)
    {
        if (level & DEBUG_WARN)
        {
            Serial.print("[WARN] ");
            Serial.println(msg);
        }
    }

    void printInfo(const char *msg)
    {
        if (level & DEBUG_INFO)
        {
            Serial.print("[INFO] ");
            Serial.println(msg);
        }
    }

    void printDebug(const char *msg)
    {
        if (level & DEBUG_DEBUG)
        {
            Serial.print("[DEBUG] ");
            Serial.println(msg);
        }
    }

    void printVerbose(const char *msg)
    {
        if (level & DEBUG_VERBOSE)
        {
            Serial.print("[VERBOSE] ");
            Serial.println(msg);
        }
    }

private:
    int level;
};

#endif // MY_SERIAL_DEBUG_H
