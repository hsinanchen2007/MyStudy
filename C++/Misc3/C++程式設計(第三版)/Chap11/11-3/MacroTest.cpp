// MacroTest.cpp
// --------------------------------------
#include <iostream>
using namespace std;

// -- 巨集指令 ---------------------------
#define MAX(x,y) ((x) > (y) ?  (x) : (y))
#define PRODUCT(x,y) ((x) * (y))
#define Merge(x, y) x##y 
#define ShowValue(x)                                     \
{                                                                       \
	cerr << #x << " 的值是: " << x << endl;    \
	cerr << "按 Enter 鍵繼續." << endl;           \
	cin.get();                                                        \
} 	

// ---- 主程式 -------------------------------------
int main()
{
	int a = 3, b = 9;
	double F1= 12.5, F2=8.38;
	cout << "MAX(a, b)   = " << MAX(a, b) << endl;
	cout << "MAX(F1, F2) = " << MAX(F1, F2) << endl;
	cout << "PRODUCT(F1, F2) = " 
		    << PRODUCT(F1+2, F2+6)  << endl;
	ShowValue(F1);
	cout << "\n執行 Merge(F,2) 的結果是: " << Merge(F,2) << endl;  
	system("PAUSE");
	return 0;
}