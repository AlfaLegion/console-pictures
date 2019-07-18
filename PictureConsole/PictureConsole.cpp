#include "PictureConsole.h"

Picture* Picture::m_this = nullptr;


LRESULT CALLBACK Picture::KeyboardProcPicture(int nCode, WPARAM wParam, LPARAM lParam)
{
	return m_this->KeyboardProc(nCode, wParam, lParam);
}
LRESULT CALLBACK Picture::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{

	if (wParam == WM_KEYDOWN)
	{
		PKBDLLHOOKSTRUCT pKey = (PKBDLLHOOKSTRUCT)lParam;
		//std::cout << pKey->vkCode << " ";
		if (m_isFlagCallBack.load())
			m_isFlagCallBack.store(false);
		else
			m_isFlagCallBack.store(true);
	}

	return CallNextHookEx(m_hHook, nCode, wParam, lParam);
}


void Picture::LoadDataFromString(const std::string& _data)
{
	m_data = _data;
}

void Picture::LoadDataFromFile(const std::string& _filename)
{
	std::fstream fl(_filename, std::ios_base::in);
	if (!fl.is_open())
	{
		std::cout << "Error opening file" << std::endl;
	}
	else {
		std::string temp;
		while (std::getline(fl, temp))
		{
			m_data.append(temp + '\n');
		}
	}
}
void Picture::Draw()
{
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	bool chFlag = true;
	while (true)
	{
		Colors color_t;
		if (m_isFlagCallBack.load())
		{
			if (chFlag)
			{
				color_t = Colors::Red;
				chFlag = false;
			}
			else
			{
				color_t = Colors::Blue; chFlag = true;
			}
		}
		else
		{
			color_t = Colors::Magenta;
		}
		for (int i = 0; i < m_data.size(); ++i)
		{

			char ch = m_data[i];


			if (ch == '1')
				SetConsoleTextAttribute(hwnd, (WORD)Colors::Black | (WORD)Colors::LightCyan);
			if (ch == '2')
				SetConsoleTextAttribute(hwnd, (WORD)Colors::Black | (WORD)Colors::Brown);
			if (ch == '3')
				SetConsoleTextAttribute(hwnd, (WORD)Colors::Black | (WORD)color_t);
			if (ch == '5')
				SetConsoleTextAttribute(hwnd, (WORD)Colors::Black | (WORD)color_t);
			std::cout << ch;
		}
		SetConsoleCursorPosition(hwnd, { 0,0 });
		Sleep(100);
	}
}

void Picture::Blink(bool _flag)const
{
	m_isFlagCallBack.store(_flag);
}

void Picture::GlobalPressChange()
{
	Picture::m_this = this;
	std::thread th([this]() {
		HMODULE hInstance = GetModuleHandle(NULL);
		m_hHook = ::SetWindowsHookExA(WH_KEYBOARD_LL, Picture::KeyboardProcPicture, NULL, NULL);
		MSG msg;
		GetMessage(&msg, NULL, NULL, NULL);

	});
	th.detach();
}
