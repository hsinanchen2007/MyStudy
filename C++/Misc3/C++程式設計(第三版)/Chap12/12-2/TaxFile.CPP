// TaxFile.cpp
// 改寫自4-4節「巢狀if-else敘述」
// 程式 Tax.cpp
// --------------------------------------
#include <iostream>
#include <fstream>
using namespace std;

// ---函數 CalculateTax() 的宣告----
double CalculateTax(double);

// ---主程式------------------------
int main()
{
	char* FileNameIn  = "Income.txt";
	char* FileNameOut = "Tax.txt";
	double Income, Tax;

	ifstream FileInput;
	ofstream FileOutput;
	FileInput.open( FileNameIn );
	FileOutput.open( FileNameOut );

	if (!FileInput)
	{
		cout << "檔案: " << FileNameIn << " 開啟失敗!"  << endl; 
		exit(1);
	}

	if (!FileOutput)
	{
		cout << "檔案: " << FileNameOut	<< " 存檔失敗!"  << endl; exit(1);
	}

	FileInput >> Income;
	Tax = CalculateTax(Income);

	cout << "您要繳的綜合所得稅是: " << Tax << " 元";

	FileOutput << "您要繳的綜合所得稅是: " << Tax << " 元";

	FileInput.close();
	FileOutput.close();
	system("PAUSE");
	return 0;
}

// ---函數 CalculateTax() 的定義-----
double CalculateTax(double GIncome)
{
	double Tax;
	if (GIncome < 0.0)
		cout << "您輸入的綜合所得淨額沒有意義!\n";
	else if (GIncome <  330000.0)
		Tax = GIncome * 0.06;
	else if (GIncome <  890000.0)
		Tax = GIncome * 0.13 - 23100;
	else if (GIncome < 1780000.0)
		Tax = GIncome * 0.21 - 94300;
	else if (GIncome < 3340000.0)
		Tax = GIncome * 0.3 - 254500;
	else
		Tax = GIncome * 0.4 - 588500;
	return Tax;
}
