﻿#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

#ifdef UNITPERFORMTESTFRAMEWORKDLL_EXPORTS
	#define UNITPERFORMTESTFRAMEWORKDLL_API __declspec(dllexport)
#else
	#define UNITPERFORMTESTFRAMEWORKDLL_API __declspec(dllimport)
#endif