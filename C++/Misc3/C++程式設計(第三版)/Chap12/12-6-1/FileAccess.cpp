// FileAccess.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

// ---函數 Add_Txt() 的宣告--------
void  Add_Txt(char *);

// ---函數 WriteString () 的宣告---
void  WriteString (char *, char *, int Mode); 

// ---函數 WriteData () 的宣告-----
void  WriteData (char *, float *, int, int Mode=1); 

				
// ---主程式-----------------------
int main ()
{
	int  const DataSize = 12;
	float Data [DataSize];
	char FileName[20]  = "SaveRecord";
	char* S1 = "A long time ago ...";

	Add_Txt(FileName);


	for (int i = 0; i < DataSize; i++)
		Data[i]= 3.8/float(1+i);

	WriteString (FileName, S1, 0); 
	WriteData   (FileName,
		Data, DataSize, 1);
	system("PAUSE");

	return 0;
}


// ---函數 Add_Txt() 的定義--------
// To add a .txt extension to a file name.
void  Add_Txt(char *Fname)
{
	int     i = 0;
	while ((Fname[i] != 0) && (Fname[i] != '.'))
		i++;
	strcpy (Fname+i,".txt");
}


// ---函數 WriteString () 的定義--------
void  WriteString (char *FileNameOut,
				   char *String, int Mode) 
				   // mode:(1 = append, 0 = replace) 
{
	ofstream FileOutput;

	if (Mode)
		FileOutput.open( FileNameOut, ios::app);
	else    
		FileOutput.open( FileNameOut, ios::out);

	if (!FileOutput) 
	{
		cout<< "檔案: " << FileNameOut << " 存檔失敗!" << endl; 
		exit(1);
	}
	FileOutput << String;		             
	FileOutput.close();
	cout << "已經存於檔案 "	<< FileNameOut << " 內." << endl;
}

// ---函數 WriteData () 的定義--------
//    mode:(1 = append, 0 = replace) 
void  WriteData (char *FileNameOut, float *Data, int Size, int Mode) 
				 
{
	ofstream FileOutput;

	if (Mode)
		FileOutput.open( FileNameOut, ios::app);
	else    
		FileOutput.open( FileNameOut, ios::out);

	if (!FileOutput) 
	{
		cout<< "檔案: " << FileNameOut	<< " 存檔失敗!" << endl; 
		exit(1);
	}
	FileOutput << "\n以下共有 " << Size 
		<< " 組數據:"    << endl;
	for (int i = 0; i<Size; i++) 
		FileOutput << Data[i] << endl;		             

	FileOutput.close();
	cout << "已經存於檔案 "	<< FileNameOut << " 內."<< endl;
}
