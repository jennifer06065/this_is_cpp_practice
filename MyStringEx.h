#pragma once
#include "MyString.h"
class CMyStringEx : public CMyString
{
public :
	using CMyString::CMyString;

	int Find(const char* pszParam);
	void OnSetString(char* pszData, int nLength);
};

