// RWFiles.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

char* FileNameIn  = "Record.txt";
char* FileNameOut = "Saved.txt";

// ---主程式------------------------
int main()
{
	const int MaxNum  = 40;
	const int MaxSize = 20;
	char  Name [MaxNum][MaxSize];
	int   Score[MaxNum];
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

	int Count=0;
	while (FileInput.peek()!= EOF && (Count < MaxNum))
	{
		FileInput >> Name[Count] >> Score[Count];
		Count++;
	}

	for (int i=0; i< Count; i++)
	{
		Score[i] = Score[i]*0.8+20;
		FileOutput << '(' << i+1 << ')'
			<< setw(12) << Name[i] << " "
			<< setw(5)  << Score[i] << endl;
	}

	FileOutput.close();
	FileInput.close();
	cout    << "已經存於檔案 " << FileNameOut << " 內." << endl;
	system("PAUSE");
	return 0;
}
