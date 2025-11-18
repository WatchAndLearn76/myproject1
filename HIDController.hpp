#pragma once
#include <hidapi/hidapi.h>

class HIDController {
private:
    hid_device* handle = nullptr;
    unsigned short vid, pid;

public:
    HIDController(unsigned short vid, unsigned short pid);
    ~HIDController();
    bool Connect();
    bool IsConnected() const;
    void Move(int x, int y);
    void Silent(int x, int y);
    void Flash();
};