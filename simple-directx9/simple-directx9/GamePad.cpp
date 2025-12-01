#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include "GamePad.h"
#include <d3dx9.h>

#define SAFE_RELEASE(p) if(p) { p->Release(); p=NULL; }

