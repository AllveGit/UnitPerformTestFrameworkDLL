#pragma once
#include "pch.h"
#include <chrono>
using namespace std::chrono;

namespace UnitPerformTest
{
	class PerformanceTimer
	{
	public:
		PerformanceTimer() : m_Start(system_clock::now()) {}

		void Clear() { m_Start = system_clock::time_point::min(); }

		bool IsStarted() const {
			return (m_Start.time_since_epoch() != system_clock::duration(0));
		}

		void Start() {
			m_Start = system_clock::now();
		}

		uint32_t GetMs() {
			if (IsStarted())
			{
				system_clock::duration timeDiff;
				timeDiff = system_clock::now() - m_Start;
				return (uint32_t)(duration_cast<milliseconds>(timeDiff).count());
			}
			return 0;
		}
	private:
		system_clock::time_point m_Start;
	};

	extern "C" {
		UNITPERFORMTESTFRAMEWORKDLL_API PerformanceTimer* CreateCheckTimer();
	}
}

