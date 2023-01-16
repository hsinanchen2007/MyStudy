// FncLib.cpp
// --------------------------------------
// 定義函數 FncB()
extern double GainG;
// extern double GainL;
// 錯誤! 此處已無法取用 GainL
double FncB(double x)
{
	double y = x*GainG;
	// double y = x*GainL
	// 錯誤!此處已無法取用 GainL
 return y;
}
