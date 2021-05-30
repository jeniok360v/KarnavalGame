#include <windows.h>
int CALLBACK
WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd)
{
	MessageBoxExA(0, "Sample text", "sample caption", 
		MB_OK|MB_ICONEXCLAMATION, 0);
	return(0);
}
