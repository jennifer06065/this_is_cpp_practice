#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

CMyString::CMyString()
	: m_pszData(NULL)
	, m_nLength(0)
{
}

CMyString::CMyString(const char* strParam)
	: m_pszData(NULL)
	, m_nLength(0)
{
	SetString(strParam);
}


CMyString::operator char* (void) const {
	return m_pszData;
}


CMyString::CMyString(const CMyString& rhs) {
	this->SetString(rhs.m_pszData);
	m_nLength = rhs.m_nLength;
}

CMyString::CMyString(CMyString&& rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;
	rhs.m_pszData = NULL;	//필수!
}

CMyString::~CMyString()
{
	Release();
}


int CMyString::SetString(const char* pszParam)
{
	int len;
	if (pszParam == NULL) return 0;
	if (m_pszData != NULL) {
		CMyString::Release();
	}
	for (len = 0; pszParam[len] != '\0'; len++);
	m_nLength = len;
	if (len == 0) return 0;
	m_pszData = new char[len+1];
	for (int i = 0; i <= len; i++) {
		m_pszData[i] = pszParam[i];
	}

	OnSetString(m_pszData, m_nLength); // virtual 을 껴넣으면서 미래의 개발자가 개입할 수 있게된다.

	return m_nLength;
}

const char* CMyString::GetString(void) const
{
	return m_pszData;
}

void CMyString::Release(void)
{
	if (m_pszData == NULL) return;
	else {
		delete[] m_pszData;
		m_pszData = NULL;
	}
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
	SetString(rhs.m_pszData);
	m_nLength = rhs.m_nLength;
	return *this;
}

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
	if (pszParam == NULL) return 0;

	int nLenParam = strlen(pszParam);
	if (nLenParam == 0)
		return 0;

	if (m_pszData == NULL) {
		SetString(pszParam);
		return m_nLength;
	}
	int nLenCur = m_nLength;

	char* pszResult = new char[nLenCur + nLenParam + 1];

	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString& rhs)
{
	CMyString result(*this);
	result.Append(rhs.m_pszData);
	return result;
}

CMyString& CMyString::operator+=(const CMyString& rhs)
{
	this->Append(rhs.m_pszData);
	return *this;
}

char CMyString::operator[](const int nIndex) const {
	return m_pszData[nIndex];
}
char& CMyString::operator[](const int nIndex) {
	return m_pszData[nIndex];
}

int CMyString::operator==(const CMyString& rhs) {
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;
	return 0;
}
int CMyString::operator!=(const CMyString& rhs) {
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;
	return 1;
}

void CMyString::OnSetString(char* pszData, int nLength) {

}