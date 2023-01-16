// FileReverse.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

char* FileNameIn  = "Original.txt";
char* FileNameOut = "Reversed.txt";

// ---主程式------------------------
int main()
{
	long CharNum, Offset;
	char Ch;
	fstream FileInput(FileNameIn, ios::in);
	if (!FileInput)
	{
		cout << "檔案 "  << FileNameIn	<< " 開啟失敗!"  << endl; 
		exit(1);
	}
	fstream FileOutput(FileNameOut, ios::out);
	if (!FileOutput)
	{
		cout << "檔案 "  << FileNameOut	<< " 存檔失敗!"  << endl; 
		exit(1);
	}
	cout << "檔案  " << FileNameIn << " 開啟完成 " << endl;

	FileInput.seekg(0L, ios::end);  //移到檔案結束的地方
	CharNum = FileInput.tellg();    //獲得字元數目
	for (Offset=1L; Offset<= CharNum; Offset++)
	{
		FileInput.seekg(-Offset, ios::end);
		Ch = FileInput.get();
		FileOutput << Ch;
	}
	FileOutput.close();
	FileInput.close();
	cout << "倒轉檔案 " << FileNameIn 
		    << " 後的內容\n已經存於檔案 " 
		    << FileNameOut << " 內." << endl;
	system("PAUSE");
	return 0;
}
