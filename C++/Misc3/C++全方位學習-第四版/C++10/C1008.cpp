//檔案名稱：d:\C++10\C1008.cpp
#include <iostream>
#include <iomanip>	//插入設定格式標題檔
using namespace std;

struct Date		//宣告Date型態資料結構
{
	int year;	//Date第1成員變數
	int month;	//Date第2成員變數
	int day;		//Date第3成員變數
};

struct Booklist	//宣告Booklist資料結構
{
	char title[25];	//Booklist第1成員變數
	char auther[9];	//Booklist第2成員變數
	char number[11];	//Booklist第3成員變數
	float price;	//Booklist第4成員變數
	Date pubDate;	//Booklist第5成員變數
};

Booklist getBook(void);	//宣告getBook函數原型
void showBook(const Booklist []);	//宣告showBook函數原型

int main(int argc, char** argv)
{
	Booklist book[2]; 	//建立Booklist型態陣列

	for(int i=0; i<2; i++)	//輸入Booklist型態資料迴圈
	{
		book[i] = getBook();	//book[i]=輸入結構資料
		cin.ignore();	//忽略最後一個輸入字元
	}

	cout << "書名\t\t\t作者\t書號\t    定價\t初版日期\n";
	showBook(book);	//傳結構陣列給showBook
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
	cout << "初版日期 (年 月 日)：";
	cin >> bl.pubDate.year >> bl.pubDate.month >> bl.pubDate.day;	//輸入第5成員資料
	cout << endl;
	return bl;	//傳回Booklist型態資料
}

void showBook(const Booklist b[])	//輸出圖書資料函數
{
	cout.precision(2);	//設定數值的有效位數
	cout.setf(ios::fixed|ios::left);	//固定小數2位數,向左對齊
	for(int j=0; j<2; j++)	//輸出圖書資料迴圈
	{
		cout << setw(24) << b[j].title;	//輸出b第1成員資料
		cout << setw(8) << b[j].auther;	//輸出b第2成員資料
		cout << setw(12) << b[j].number;	//輸出b第3成員資料
		cout << b[j].price << '\t';	//輸出b第4成員資料
		cout << b[j].pubDate.month << '-'
		     << b[j].pubDate.day << '-'
		     << b[j].pubDate.year << '\n';	//輸出b第5成員資料
	}
}
