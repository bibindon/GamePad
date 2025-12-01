#pragma once

#ifndef DIRECTINPUT_VERSION
// constexprÇ…ïœä∑Ç≈Ç´ÇÈÅAÇ∆Ç¢Ç§åxçêÇ™ï\é¶Ç≥ÇÍÇÈÇ™ïœä∑ÇµÇƒÇÕÇ¢ÇØÇ»Ç¢ÅB
#define DIRECTINPUT_VERSION 0x0800
#endif

#include <dinput.h>
#include <unordered_map>
#include <deque>

#include "GamePad.h"

enum class eGamePadButtonType;
enum class eGamePadButtonState;

class GamePadDirectInput
{
public:

    static bool Init(LPDIRECTINPUT8 DI, HWND hwnd);
    static void Finalize();
    static void Update();
    static bool IsHold(eGamePadButtonType button);
    static bool IsUp(eGamePadButtonType button);
    static bool IsDownFirst(eGamePadButtonType button);
    static bool IsDown(eGamePadButtonType button);
    static float GetLeftRadian();
    static bool IsLeftStickUsed();
    static bool CheckSimultaneous(eGamePadButtonType button);

    static LPDIRECTINPUT8 m_DI;
    static LPDIRECTINPUTDEVICE8 m_DIDevice;
    struct GamePadInfo
    {
        std::unordered_map<eGamePadButtonType, eGamePadButtonState> m_statusMap;
    };
    static std::deque<GamePadInfo> m_deqButton;

private:
    static bool CreateDevice(HWND hwnd);
    static BOOL StartGamePadControl();
    static float m_leftRadian;
    static bool m_bLeftStickUsed;
    static const int KEY_DEQUE_MAX_SIZE = 300;
    static const int SIMULTANEOUS_ALLOW_FRAME = 3;

    static bool m_bConnected;
};


