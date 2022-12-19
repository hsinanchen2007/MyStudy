占用空间有点大。。。
```
#include<iostream>
#include<list>

using namespace std;

void printList(const list<int> &L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

list<int> reverseList(list<int> &L, int m, int n)
{
	list<int> L2;
	list<int> L3;

	for (int i = 0; i < L.size() - n; i++)
	{
		L3.push_back(L.back());
		L.pop_back();
	}

	for (int i = 0; i < m-1; i++)
	{
		L2.push_back(L.front());
		L.pop_front();
	}

	L3.reverse();
	L.reverse();

	int num = L.size();
	for (int i = 0; i < num; i++)
	{
		L2.push_back(L.front());
		L.pop_front();
	}


	for (int i = 0; i < L3.size(); i++)
	{
		L2.push_back(L3.front());
		L3.pop_front();
	}


	return L2;
}

void test1()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	L.push_back(5);

	int m = 1; 
	int n = 5;

	printList(L);
	list<int> L1;


	L1 = reverseList(L, m,n);
	printList(L1);

}

int main()
{
	test1();
	system("pause");
	return 0;
}
```
