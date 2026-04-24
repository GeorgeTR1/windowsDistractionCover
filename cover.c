#include <windows.h>

#pragma comment (lib, "user32")
#pragma comment (lib, "Gdi32")
#pragma comment (lib, "Kernel32")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int main() {
   HINSTANCE hInstance = GetModuleHandle(NULL);
   WNDCLASS wndclass = {0};
	HWND hwnd;
	MSG msg;
	
	wndclass.style = CS_DBLCLKS;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = "cover";
	
	RegisterClass(&wndclass);
	
	hwnd = CreateWindowEx(WS_EX_TOPMOST, //Extended Window Styles
	   wndclass.lpszClassName, // window class name
		"Distraction Cover", // window caption
		WS_CAPTION | WS_SIZEBOX | WS_SYSMENU, // window style
		CW_USEDEFAULT, 0, 200, 200, NULL, NULL,
		hInstance, // program instance handle
		NULL);
		
	//ShowWindow (hwnd, iCmdShow);
   ShowWindow (hwnd, SW_SHOWNORMAL);
	
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
   
   //since we don't use WinMain the program hangs if we return normally
   ExitProcess(0);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		
	case WM_LBUTTONDBLCLK:
		if (GetWindowLong(hwnd, GWL_STYLE) & WS_POPUP) {
			SetWindowLong(hwnd, GWL_STYLE, WS_CAPTION | WS_SIZEBOX | WS_SYSMENU);
		} else {
			SetWindowLong(hwnd, GWL_STYLE, WS_POPUP);
		}
		ShowWindow(hwnd, SW_SHOW);
		
		return 0;
	}
	
	return DefWindowProc(hwnd, message, wParam, lParam);
}