// Priority.cpp
// --------------------------------------
#include <iostream>
using namespace std;

namespace NS     // 宣告名稱空間 NS
{
	int M = 10;                   // (1)
	float x =1.0,  y = 2.0;   // (2)
	char C = 'G';                 // (3)
}

// ----主程式-----------------------
int main()
{
	NS::M = 6;                       //  更動(1)中的M
	{
		float y = 7.5;                //  (4)定義局部變數 y
		using namespace NS;   //  using 指令
		x = 5.6;                        //  更動(2) 中的 x
		cout << y <<endl;	     //  輸出(4) 中的 y (=7.5)
	}
	//C = 'P';      // 錯誤!此處已無法取用 (3) 中的 C 
	system("PAUSE");
	return 0;
}