//  Decoding.cpp
// --------------------------------------
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// ---��� GetString () ���ŧi--------
void  GetString (char *FileNameIn, char *String);
// ---��� Decode() ���ŧi--------------
void  Decode(char *String);
// ---��� WriteString () ���ŧi--------
void  WriteString (char *, char *, int Mode);

const int MaxLength = 40;

// ---�D�{��----------------------------
int main ()
{
	char FileNameIn[20]  = "EncodedText.txt";
	char FileNameOut[20] = "DecodedText.txt";
	char String[MaxLength];
	GetString(FileNameIn, String);
	Decode(String);
	cout << "�ѽX�᪺���e�O:\n" << String << endl;
	WriteString (FileNameOut, String, 0);
	system("PAUSE");
	return 0;
}

// ---��� GetString () ���w�q-----------
void  GetString (char *FileNameIn, char *String)
{
	ifstream FileInput;
	FileInput.open( FileNameIn );
	if (!FileInput)
	{ cout << "�ɮ�: " << FileNameIn<< " �}�ҥ���!"  << endl; exit(1); }
	FileInput.getline(String,MaxLength);
	FileInput.close();
	cout << "�ɮ�: " << FileNameIn
		    << " �}�ҧ���,\n�U�C�O�즳�ɮפ��e:\n"
		    << String << endl;
}

// ---��� Decode() ���w�q---------------
void Decode(char *String)
{
	char Codes[28]="DOJKZCTMYPAWHUQNBVGSRFXLIE ";
	char ABC[28]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	int  i, j, Size=strlen(String);
	for(i=0; i<Size;i++)
	{ 
		j=0;
		while(String[i]!=Codes[j] && j<26)
			j++;
		String[i]=ABC[j];
	}
	return;
}

// ---��� WriteString () ���w�q------------
void  WriteString (char *FileNameOut,   char *String, int Mode)
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
	FileOutput << String;
	FileOutput.close();
	cout << "�w�g�s���ɮ� "	<< FileNameOut << " ��." << endl;
}
