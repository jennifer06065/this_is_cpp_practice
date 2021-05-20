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
	/*
	bool flag;
	for (int i = 0; i < pszlen; i++) {
		flag = 0;
		for (int j = 0; pszParam[j] != '\0'; j++) {
			if (i + j >= pszlen) {
				return -1;
			}
			if (pszParam[j] == pszData[i+j]) {
				continue;
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		else return i;
	}
	return -1;
	*/

	char* temp = strstr(pszData, pszParam);
	if (temp == NULL) return -1;
	else return temp - pszData;
}