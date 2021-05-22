#define _CRT_SECURE_NO_WARNINGS
#include "MyStringEx.h"
#include <iostream>
#include <cstring>
using namespace std;

int CMyStringEx::Find(const char* pszParam) {
	if (GetString() == NULL || GetLength() == 0) return -1;
	int pszlen = GetLength();
	char* pszData = new char[pszlen];
	strcpy(pszData, GetString());

	char* temp = strstr(pszData, pszParam);
	if (temp == NULL) return -1;
	else return temp - pszData;
}

void CMyStringEx::OnSetString(char* pszData, int nLength) {
	if (strcmp(pszData, "¸Û¸ÛÀÌ¾Æµé") == 0)
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "*ÂøÇÑ¾Æµé*");
}