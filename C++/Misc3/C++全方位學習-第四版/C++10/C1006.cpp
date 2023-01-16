//檔案名稱：d:\C++10\C1006.cpp
#include <iostream>
#include <iomanip>	//插入設定格式標題檔
using namespace std;

struct Booklist	//宣告Booklist資料結構
{
	char title[24];	//Booklist第1成員變數
	char auther[9];	//Booklist第2成員變數
	char number[11];	//Booklist第3成員變數
	float price;	//Booklist第4成員變數
};

Booklist getBook(void);	//宣告getBook函數原型
void showBook(const Booklist &);	//宣告showBook函數原型

int main(int argc, char** argv)
{
	Booklist CPP; 	//建立Booklist型態變數
	Booklist DL; 	//建立Booklist型態變數

	CPP = getBook();	//CPP=輸入結構型態資料
	cin.ignore();	//忽略最後一個輸入字元
	DL = getBook();	//CPP=輸入結構型態資料

	cout << "書名\t\t\t作者\t\t書號\t\t定價\n";
	showBook(CPP);
	showBook(DL);
	return 0;
}

Booklist getBook(void) 	//輸入圖書資料函數
{
	Booklist bl;	//建立Booklist型態變數

	cout << "請輸入書名：";
	cin.getline(bl.title, 24);	//輸入第1成員資料
	cout << "請輸入作者：";
	cin.getline(bl.auther, 8);	//輸入第2成員資料
	cout << "請輸入書號：";
	cin.getline(bl.number, 10);	//輸入第3成員資料
	cout << "請輸入定價：";
	cin >> bl.price;	//輸入第4成員資料
	cout << endl;
	return bl;	//傳回Booklist型態資料
}

void showBook(const Booklist &b)	//輸出圖書資料函數
{
	cout.precision(2);	//設定數值的有效位數
	cout.setf(ios::fixed|ios::left);	//固定小數2位數,向左對齊
	cout << setw(24) << b.title;	//輸出CPP第1成員資料
	cout << setw(16) << b.auther;	//輸出CPP第2成員資料
	cout << setw(16) << b.number;	//輸出CPP第3成員資料
	cout << b.price << '\n';	//輸出CPP第4成員資料
}
