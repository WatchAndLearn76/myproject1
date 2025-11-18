#include "Aimbot.hpp"
#include <windows.h>

Aimbot::Aimbot(HIDController* hid) : m_hid(hid) {}

void Aimbot::MoveMouse(int x, int y) {
    if (m_hid && m_hid->IsConnected()) {
        m_hid->Move(x, y);
    }
}

void Aimbot::SilentMove(int x, int y) {
    if (m_hid && m_hid->IsConnected()) {
        m_hid->Silent(x, y);
    }
}

void Aimbot::Flash() {
    if (m_hid && m_hid->IsConnected()) {
        m_hid->Flash();
    }
}

void Aimbot::Run() {
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
        // Burada ekran yakalama ve hedef tespiti olacak
        // cv::Mat screen = CaptureScreen();
        // ProcessScreen(screen);
    }
}

void Aimbot::ProcessScreen(const cv::Mat& screen) {
    // Renk tespiti, contour bulma, centroid hesaplama
    auto center = m_colorSorter.FindTarget(screen);
    if (center.x != -1) {
        int dx = center.x - screen.cols / 2;
        int dy = center.y - screen.rows / 2 - m_config.target_offset;
        MoveMouse(dx * m_config.aim_speed, dy * m_config.aim_speed);
    }
}