
#include "PictureConsole.h"

int main()
{
	

	Picture pic("Yolochka.txt");
	//pic.Blink(true);
	pic.GlobalPressChange();
	pic.Draw();

	/*DWORD idT = GetCurrentThreadId();
	HMODULE hInstance = GetModuleHandle(NULL);
	hHook = SetWindowsHookExA(WH_KEYBOARD_LL, KeyboardProc, hInstance, NULL);
	if (!hHook)
		std::cout << GetLastError() << std::endl;
	MSG msg;
	GetMessage(&msg, NULL, NULL, NULL);*/



	//HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);

	//std::string str;
	//std::fstream fl("yolochka.txt", std::ios_base::in);
	//if (!fl.is_open())
	//{
	//	std::cout << "error" << std::endl;
	//}
	//else
	//{

	//	std::string temp;
	//	while (std::getline(fl, temp))
	//	{
	//		str.append(temp+'\n');
	//	}
	//	std::uniform_int_distribution<int> uid(0, 2);
	//	std::random_device rd;
	//	bool chFlag = true;
	//	while (true)
	//	{
	//		WORD color_t;
	//		if (isFlag.load())
	//		{
	//			if (chFlag)
	//			{
	//				color_t = Red;
	//				chFlag = false;
	//			}
	//			else
	//			{
	//				color_t = Blue; chFlag = true;
	//			}
	//		}
	//		else
	//		{
	//			color_t = Magenta;
	//		}
	//		for (int i = 0; i < str.size(); ++i)
	//		{

	//			char ch = str[i];


	//			if (ch == '1')
	//				SetConsoleTextAttribute(hwnd, (WORD)(Black | LightCyan));
	//			if (ch == '2')
	//				SetConsoleTextAttribute(hwnd, (WORD)(Black | Brown));
	//			if (ch == '3')
	//				SetConsoleTextAttribute(hwnd, (WORD)(Black | color_t));
	//			if (ch == '5')
	//				SetConsoleTextAttribute(hwnd, (WORD)(Black | color_t));
	//			std::cout << ch;
	//		}
	//		SetConsoleCursorPosition(hwnd, { 0,0 });
	//		Sleep(200);
	//	}

	//	//SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	//	//std::cout << str << std::endl;
	//	std::cin.get();
	//	std::cin.get();
	//	UnhookWindowsHookEx(hHook);
	//}
}