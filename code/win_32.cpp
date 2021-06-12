#include <windows.h>
/*
typedef struct tagWNDCLASSA {
	UINT      style;
	WNDPROC   lpfnWndProc;
	int       cbClsExtra;
	int       cbWndExtra;
	HINSTANCE hInstance;
	HICON     hIcon;
	HCURSOR   hCursor;
	HBRUSH    hbrBackground;
	LPCSTR    lpszMenuName;
	LPCSTR    lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;
*/

LRESULT CALLBACK MainWindowCallback(
	HWND   Window,
	UINT   Message,
	WPARAM WParam,
	LPARAM LParam)
{
	LRESULT Result = 0;
	switch(Message)
	{
		case WM_SIZE:{//user changes size of the window
			OutputDebugStringA("WM_SIZE\n");
		}break;
		
		case WM_DESTROY:{//window deleted
			OutputDebugStringA("WM_DESTROY\n");
		}break;

		case WM_CLOSE:{//user ckicked X at the rigth top corner
			OutputDebugStringA("WM_CLOSE\n");
		}break;
		
		case WM_ACTIVATEAPP:{//app is active
			OutputDebugStringA("WM_ACTIVATEAPP\n");
		}break;
		
		default:{
			Result = DefWindowProc(Window, Message, WParam, LParam);
//			OutputDebugStringA("default\n");
		}break;
	}
	return (Result);
}

int CALLBACK
WinMain(HINSTANCE Instance,
	HINSTANCE PrevInstance,
	LPSTR     CommandLine,
	int       ShowCode)
{
	WNDCLASSA WindowClass = {};
	// CS_OWNDC, CS_HREDRAW, CS_VREDRAW ??
	WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
	WindowClass.lpfnWndProc = MainWindowCallback;
	WindowClass.hInstance = Instance;
	//WindowClass.hIcon =;
	WindowClass.lpszClassName = "GameWindowClass";
	
	if(RegisterClass(&WindowClass)){
		HWND WindowHandle =
			CreateWindowEx(
				0,	//DWORD     dwExStyle,
				WindowClass.lpszClassName,	//LPCWSTR   lpClassName,
				"Window Name",	//LPCWSTR   lpWindowName,
				WS_OVERLAPPEDWINDOW|WS_VISIBLE,	//DWORD     dwStyle,
				CW_USEDEFAULT,	//int       X,
				CW_USEDEFAULT,	//int       Y,
				CW_USEDEFAULT,	//int       nWidth,
				CW_USEDEFAULT,	//int       nHeight,
				0,	//HWND      hWndParent,
				0,	//HMENU     hMenu,
				Instance,	//HINSTANCE hInstance,
				0);	//LPVOID    lpParam
		
		if(WindowHandle){
			MSG Message;
			while(1){
				BOOL MessageResult = GetMessage(&Message, 0,0,0);
				if (MessageResult > 0){
					TranslateMessage(&Message);
					DispatchMessage(&Message);
				}
				else{
					break;
				}
			}
		}
	}
	else{
		// RegisterClassW fails
	}
	
	return 0;
}

















