// Reserved.cpp
// --------------------------------------
#include <iostream>
using namespace std;
// ---- 主程式 -------------------------------------
int main()
{
	cout << "行號    : " << __LINE__ << endl;
	cout << "檔名    : " << __FILE__ << endl;
	cout << "編譯日期: " << __DATE__ << endl;
	cout << "編譯時間: " << __TIME__ << endl;
	#line 120 "Test File.cpp"       
	cout << "執行 #line 120 \"Test File.cpp\"之後: "
		    << endl; 
	cout << "行號    : " << __LINE__ << endl;
	cout << "檔名    : " << __FILE__ << endl;
	system("PAUSE");
	return 0;   
}
