// Check.cpp
// --------------------------------------
#include <iostream>
using namespace std;

namespace         // 未命名的名稱空間
{
	double GainL=5.6;          // GainL 被限制
	double FncA(double x)    // FncA() 被限制
		{return x*GainL;}
}
double GainG = 3.8;		      // 全域常數 GainG
double FncB(double);	          // FncB() 的原型

// ----主程式-----------------------
int main()
{
	cout << "FncA(5)是: "
			<< FncA(5) << endl;   //  呼叫 FncA()
	cout << "FncB(5)是: "
			<< FncB(5) << endl;   //  呼叫 FncB()
   system("PAUSE");
   return 0;
}
