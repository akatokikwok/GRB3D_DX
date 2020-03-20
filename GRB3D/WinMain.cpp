#include <Windows.h>


//define a customize wndclassex
LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage( 112112 );
		break;
	}
	return DefWindowProc(hwnd, msg, wParam,lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	  lpCmdLine,
	int	nCmdShow
)
{
	//while (true);
	
	//register grb's window
	WNDCLASSEX wc = { 0 };//����wndclassex������
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;//CS_OWNDC ::Allocates a unique device context for each window in the class.
	wc.lpfnWndProc = WndProc;//refer to Line5
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;//�����������:���
	wc.hIcon =nullptr ;
	wc.hbrBackground = nullptr;
	wc.hCursor = nullptr;
	wc.lpszMenuName = nullptr;

	const auto pClassName = "LeiMingGRB";//����ǰ����������� ����ȡֵ
	wc.lpszClassName = pClassName;

	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	//to create grbs window
	HWND hwnd = CreateWindowEx(
	0,pClassName,"������",
	WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		1000,200,640,480,
		nullptr,nullptr,hInstance,nullptr	
	);

	//to display this created window
	ShowWindow(hwnd, SW_SHOW);//use Showwindow func

	//to Pump message
	MSG msg; BOOL gResult;

	while (gResult=GetMessage(&msg,nullptr,0,0)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	};
	if (gResult==-1)
	{
		return -1;
	} 
	else
	{
		return msg.wParam;//���wm_quit message��postquitmessage��msdn˵��
	}

	return 0;
}