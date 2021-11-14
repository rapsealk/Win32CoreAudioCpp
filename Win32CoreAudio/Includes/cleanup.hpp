#pragma once

#include <combaseapi.h>

#include "../Includes/util.hpp"

class CoUninitializeOnExit {
public:
	~CoUninitializeOnExit() {
		CoUninitialize();
	}
};

class CloseHandleOnExit {
private:
	HANDLE m_h;
public:
	CloseHandleOnExit(HANDLE h) : m_h(h) {}
	~CloseHandleOnExit() {
		if (!CloseHandle(m_h)) {
			LOGE("CloseHandle failed: last error is %d", GetLastError());
		}
	}
};