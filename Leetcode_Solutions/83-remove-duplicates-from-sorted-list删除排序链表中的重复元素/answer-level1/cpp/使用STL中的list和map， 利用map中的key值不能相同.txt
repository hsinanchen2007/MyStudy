```
#include <iostream>
#include <list>
#include <map>
using namespace std;

void test1()
{
	list<int> L;
	L.push_back(1);
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(3);

	map<int, int> M;

	// use map feature, no same key;
	int num = L.size();
	for (int i = 0; i < num; i++)
	{
		M.insert(make_pair(L.front(), i));
		L.pop_front();
	}

	// cout the result in map()
	for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
	{
		cout << it->first << " ";
	}
	cout << endl;

}

int main()
{
	test1();
	system("pause");
	return 0;
}
```
