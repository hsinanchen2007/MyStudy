// ConvFile.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

char* FileNameIn  = "Original.txt";
char* FileNameOut = "Converted.txt";

// ---函數 Sort() 的宣告----
int Sort(char X);

// ---主程式------------------------
int main()
{
	char C;
	fstream FileInput(FileNameIn, ios::in);
	if (!FileInput)
	{
		cout << "檔案: "  << FileNameIn	<< " 開啟失敗!"   << endl; 
		exit(1);
	}
	fstream FileOutput(FileNameOut, ios::out);
	if (!FileOutput)
	{
		cout<< "檔案: " << FileNameOut	<< " 存檔失敗!" << endl; 
		exit(1);
	}
	while ((C=FileInput.get()) != EOF)
	{
		switch (Sort(C))
		{
		case 1:
			FileOutput << char(toupper(C));
			break;
		case 0:  case 2:
		case 3:  case 4:
			FileOutput << C ;
			break;
		case 5:
			FileOutput << "Other" << endl;
			break;
		default:
			cout << "程式有問題!" << endl;
		}
	}

	FileOutput.close();
	FileInput.close();
	cout << "已經存於檔案 " << FileNameOut << " 內." << endl;
	system("PAUSE");
	return 0;
}

// ---函數 Sort() 的定義---------
int Sort(char X)
{
	if (isupper(X))
		return 0;
	else if (islower(X))
		return 1;
	else if (isdigit(X))
		return 2;
	else if (isspace(X))
		return 3;
	else if (ispunct(X))
		return 4;
	else
		return 5;
}
