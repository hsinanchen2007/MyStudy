// FileAccess.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

// ---��� Add_Txt() ���ŧi--------
void  Add_Txt(char *);

// ---��� WriteString () ���ŧi---
void  WriteString (char *, char *, int Mode); 

// ---��� WriteData () ���ŧi-----
void  WriteData (char *, float *, int, int Mode=1); 

				
// ---�D�{��-----------------------
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


// ---��� Add_Txt() ���w�q--------
// To add a .txt extension to a file name.
void  Add_Txt(char *Fname)
{
	int     i = 0;
	while ((Fname[i] != 0) && (Fname[i] != '.'))
		i++;
	strcpy (Fname+i,".txt");
}


// ---��� WriteString () ���w�q--------
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
		cout<< "�ɮ�: " << FileNameOut << " �s�ɥ���!" << endl; 
		exit(1);
	}
	FileOutput << String;		             
	FileOutput.close();
	cout << "�w�g�s���ɮ� "	<< FileNameOut << " ��." << endl;
}

// ---��� WriteData () ���w�q--------
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
		cout<< "�ɮ�: " << FileNameOut	<< " �s�ɥ���!" << endl; 
		exit(1);
	}
	FileOutput << "\n�H�U�@�� " << Size 
		<< " �ռƾ�:"    << endl;
	for (int i = 0; i<Size; i++) 
		FileOutput << Data[i] << endl;		             

	FileOutput.close();
	cout << "�w�g�s���ɮ� "	<< FileNameOut << " ��."<< endl;
}
