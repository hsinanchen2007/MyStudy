//  Encoding.cpp
// --------------------------------------
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// ---��� GetString () ���ŧi--------
void  GetString (char *FileNameIn, char *String);
// ---��� Encode() ���ŧi------------
void  Encode(char *String);
// ---��� WriteString () ���ŧi------
void  WriteString (char *, char *, int Mode);

const int MaxLength = 40;

// ---�D�{��--------------------------
int main ()
{
	char FileNameIn[20]  = "OriginalText.txt";
	char FileNameOut[20]  = "EncodedText.txt";
	char String[MaxLength];
	GetString(FileNameIn, String);
	Encode(String);
	cout << "�s�X�᪺���e�O:\n" << String << endl;
	WriteString (FileNameOut, String, 0);
	system("PAUSE");
	return 0;
}

// ---��� GetString () ���w�q--------
void  GetString (char *FileNameIn, char *String)
{
	ifstream FileInput;
	FileInput.open( FileNameIn );

	if (!FileInput)
	{
		cout << "�ɮ�: " << FileNameIn << " �}�ҥ���!"  << endl; 
		exit(1);
	}
	FileInput.getline(String,MaxLength);

	FileInput.close();
	cout << "�ɮ�: " << FileNameIn
		    << " �}�ҧ���,\n�U�C�O�즳�ɮפ��e:\n"
		    << String << endl;
}

// ---��� Encode() ���w�q-----------
void Encode(char *String)
{
	char Codes[28]="DOJKZCTMYPAWHUQNBVGSRFXLIE ";
	char ABC[28]  ="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char abc[28]  ="abcdefghijklmnopqrstuvwxyz ";
	int  i, j, Size=strlen(String);

	for(i=0; i<Size;i++)
	{ 
		j=0;
		while(String[i]!=ABC[j] && String[i]!=abc[j] && j<26)
			j++;
		String[i]=Codes[j];
	}
	return;
}

// ---��� WriteString () ���w�q--------
void  WriteString (char *FileNameOut,
				   char *String, int Mode)
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
