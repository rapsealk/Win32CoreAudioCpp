#pragma once

#include <mmdeviceapi.h>

class CPrefs {
public:
	IMMDevice* m_pMMDevice;
	HMMIO m_hFile;
	bool m_bInt16;
	PWAVEFORMATEX m_pwfx;
	LPCWSTR m_szFilename;

	CPrefs(int argc, char* argv[], HRESULT& hres);
	~CPrefs();
};