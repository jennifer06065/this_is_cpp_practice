#include "MyStringEx.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	CMyStringEx strTest;
	strTest.SetString("�۸��̾Ƶ�");
	cout << strTest << endl;

	return 0;
}