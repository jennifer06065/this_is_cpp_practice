#pragma once
class CMyString
{
public :
	CMyString();
	CMyString(const char* strParam); //변환생성자
	CMyString(const CMyString& rhs); //복사생성자
	CMyString(CMyString&& rhs); //이동생성자
	~CMyString();

private:
	//문자열을 저장하기 위해 동적할당한 메모리를 가리키는 포인터
	char* m_pszData;
	//저장된 문자열의 길이
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString(void) const;
	void Release(void);
	CMyString& operator=(const CMyString& rhs);
	operator char* (void) const;//변환함수 : 변환 형식 지정할 수 없음, 
	int GetLength() const;
	int Append(const char* pszParam);
	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	char operator[](const int nIndex) const;
	char& operator[](const int nIndex);
	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);
	virtual void OnSetString(char* pszData, int nLength);
};

