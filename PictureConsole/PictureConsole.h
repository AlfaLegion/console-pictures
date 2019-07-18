#pragma once
#include<fstream>
#include<thread>
#include<string>
#include<vector>
#include<iostream>
#include<Windows.h>
#include<random>
#include<atomic>

class Picture
{
public:
	enum class Colors
	{
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};
private:
	std::string				 m_data;
	mutable std::atomic_bool m_isFlagCallBack;
	HHOOK                    m_hHook;
	static Picture*			 m_this;

private:
	static LRESULT CALLBACK KeyboardProcPicture(int nCode, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);


public:
	Picture() = default;
	explicit Picture(const std::string& _filename):m_data(std::string()), m_isFlagCallBack(false)
	{
		LoadDataFromFile(_filename);
	}
	
	void LoadDataFromString(const std::string& _data);
	void LoadDataFromFile(const std::string& _filename);
	void Draw();
	void Blink(bool _flag)const;


	void GlobalPressChange();




};