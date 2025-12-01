#pragma once

#ifndef DIRECTINPUT_VERSION
// constexprに変換できる、という警告が表示されるが変換してはいけない。
#define DIRECTINPUT_VERSION 0x0800
#endif

#include <dinput.h>
#include <unordered_map>
#include <deque>

#include "GamePadDirectInput.h"
#include "GamePadXInput.h"

// Monostate pattern.
enum class eGamePadButtonType
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    X,
    Y,
    A, // Confirm
    B, // Cancel
    Z_LEFT,
    Z_RIGHT,
    Z_UP,
    Z_DOWN,
    L1,
    R1,
    L2,
    R2,
    BACK,
    START,
    UNKNOWN,
};

enum class eGamePadButtonState
{
    NONE,
    DOWN_FIRST,
    DOWN,
    HOLD,
    UP,
    MAX,
};

// XInputとDirectInputがある

