// FileReverse.cpp
// --------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

char* FileNameIn  = "Original.txt";
char* FileNameOut = "Reversed.txt";

// ---�D�{��------------------------
int main()
{
	long CharNum, Offset;
	char Ch;
	fstream FileInput(FileNameIn, ios::in);
	if (!FileInput)
	{
		cout << "�ɮ� "  << FileNameIn	<< " �}�ҥ���!"  << endl; 
		exit(1);
	}
	fstream FileOutput(FileNameOut, ios::out);
	if (!FileOutput)
	{
		cout << "�ɮ� "  << FileNameOut	<< " �s�ɥ���!"  << endl; 
		exit(1);
	}
	cout << "�ɮ�  " << FileNameIn << " �}�ҧ��� " << endl;

	FileInput.seekg(0L, ios::end);  //�����ɮ׵������a��
	CharNum = FileInput.tellg();    //��o�r���ƥ�
	for (Offset=1L; Offset<= CharNum; Offset++)
	{
		FileInput.seekg(-Offset, ios::end);
		Ch = FileInput.get();
		FileOutput << Ch;
	}
	FileOutput.close();
	FileInput.close();
	cout << "�����ɮ� " << FileNameIn 
		    << " �᪺���e\n�w�g�s���ɮ� " 
		    << FileNameOut << " ��." << endl;
	system("PAUSE");
	return 0;
}
