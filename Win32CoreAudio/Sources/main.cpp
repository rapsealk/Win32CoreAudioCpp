#include <Audioclient.h>
#include <mmdeviceapi.h>
#include <objbase.h>
#include <Windows.h>
#include <mmsystem.h>
#include <avrt.h>
#include <functiondiscoverykeys_devpkey.h>

#include "../Includes/cleanup.hpp"
#include "../Includes/prefs.hpp"
#include "../Includes/util.hpp"

int main(int argc, char* argv[])
{
	HRESULT hres = S_OK;
	hres = CoInitialize(NULL);
	if (FAILED(hres))
	{
		LOGE("CoInitialize failed: hr = 0x%08x", hres);
		return -__LINE__;
	}

	CoUninitializeOnExit cuoe;

	// ===========================================================
	hres = S_OK;

	CPrefs prefs(argc, argv, hres);
	if (FAILED(hres))
	{
		LOGE("CPrefs::CPrefs constructor failed: hr = 0x%08x", hres);
		return -__LINE__;
	}
	if (S_FALSE == hres)
	{
		return 0;
	}

	// Create a loopback-capture-has-started event.
	HANDLE hStartedEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (NULL == hStartedEvent)
	{
		LOGE("CreatEvent failed: last error is %u", GetLastError());
		return -__LINE__;
	}
	CloseHandleOnExit closeStartedEvent(hStartedEvent);
	// ===========================================================

	return 0;
}