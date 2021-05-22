#pragma once
class CMyString
{
public :
	CMyString();
	CMyString(const char* strParam); //��ȯ������
	CMyString(const CMyString& rhs); //���������
	CMyString(CMyString&& rhs); //�̵�������
	~CMyString();

private:
	//���ڿ��� �����ϱ� ���� �����Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	//����� ���ڿ��� ����
	int m_nLength;
public:
	int SetString(const char* pszParam);
	const char* GetString(void) const;
	void Release(void);
	CMyString& operator=(const CMyString& rhs);
	operator char* (void) const;//��ȯ�Լ� : ��ȯ ���� ������ �� ����, 
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

