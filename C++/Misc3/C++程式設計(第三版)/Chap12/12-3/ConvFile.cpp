// ConvFile.cpp
// --------------------------------------
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

char* FileNameIn  = "Original.txt";
char* FileNameOut = "Converted.txt";

// ---��� Sort() ���ŧi----
int Sort(char X);

// ---�D�{��------------------------
int main()
{
	char C;
	fstream FileInput(FileNameIn, ios::in);
	if (!FileInput)
	{
		cout << "�ɮ�: "  << FileNameIn	<< " �}�ҥ���!"   << endl; 
		exit(1);
	}
	fstream FileOutput(FileNameOut, ios::out);
	if (!FileOutput)
	{
		cout<< "�ɮ�: " << FileNameOut	<< " �s�ɥ���!" << endl; 
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
			cout << "�{�������D!" << endl;
		}
	}

	FileOutput.close();
	FileInput.close();
	cout << "�w�g�s���ɮ� " << FileNameOut << " ��." << endl;
	system("PAUSE");
	return 0;
}

// ---��� Sort() ���w�q---------
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
