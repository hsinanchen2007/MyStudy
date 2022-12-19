```
#include<iostream>
#include <list>

using namespace std;

void printList(list<int> &L)
{
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1()
{
	list<int> L;
	L.push_back(4);
	L.push_back(5);
	L.push_back(1);
	L.push_back(9);

	printList(L);

	L.remove(1);
	printList(L);
}

int main()
{
	test1();
	system("pause");
	return 0;
}
```
