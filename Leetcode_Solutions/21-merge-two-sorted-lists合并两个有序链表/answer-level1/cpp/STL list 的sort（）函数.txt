```
#include<iostream>
#include <list>

using namespace std;

void printList(const list<int> L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	list<int> L1;
	list<int> L2;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(4);

	L2.push_back(1);
	L2.push_back(3);
	L2.push_back(4);
	
	int num = L2.size();

	for (int i = 0; i < num; i++)
	{
		L1.push_back(L2.front());
		L2.pop_front();
	}

	L1.sort();
	printList(L1);

	system("pause");
	return 0;

}
```
