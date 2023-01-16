// Exception.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// --- 函數 Divide() 的原型 -----
float Divide(float, float);

// ----主程式-----------------------
int main()
{
	float M, N;
	try
	{
		cout << "請輸入兩個數字,\n" << endl;
		cout << "請輸入第一個數字 :" << endl;
		 cin  >> M;
		cout << "請輸入第二個數字 :" << endl;
		 cin  >> N;
		cout << "您輸入了 : " << M << " 和 " << N << endl;
		cout << "這兩個數字相除的結果是: "
			    << Divide(M,N) << endl;
	}

	catch (char* pError)
	{
		cerr << "發生異常: " << pError << endl;
	}
	system("PAUSE");
	return 0;
}

