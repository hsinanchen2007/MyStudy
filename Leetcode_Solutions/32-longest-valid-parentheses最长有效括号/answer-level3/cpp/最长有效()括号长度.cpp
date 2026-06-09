#include <iostream>;
#include <string>;
#include <vector>;
#include <stack>; 
#include<set>;
using namespace std;

class MyClass
{
public:
	MyClass();
	MyClass(int index, char value);
	int GetIndex();
	char GetValue();
	~MyClass();

private:
	int _index;
	char _value;
};

MyClass::MyClass()
{
	
}

MyClass::MyClass(int index, char value)
{
	_index = index;
	_value = value;
}

int MyClass::GetIndex()
{
	return _index;
}

char MyClass::GetValue()
{
	return _value;
}



MyClass::~MyClass()
{
}

int main(){
	vector<char> str;
	string shurustr;
	while (cin >> shurustr)
	{
		vector<set<int>> shuchu;
		for (int i = 0; i < shurustr.size(); i++)
		{
			str.push_back(shurustr[i]); //填充数据
		}
		vector<vector<MyClass>> vec2;
		vector<MyClass> statemp;
		int i = 0;
		for (std::vector<char>::iterator it = str.begin(); it != str.end(); ++it)
		{
			if (*it == '(' || *it == ')')
			{
				if (statemp.empty())
				{
					if (*it != ')')
					{
						statemp.push_back(MyClass(i++, *it));
					}
				}
				else
				{
					statemp.push_back(MyClass(i++, *it));
				}
			}
			else
			{
				if (!statemp.empty()) {
					vec2.push_back(statemp);
					vector<MyClass>().swap(statemp);
					i = 0;
				}
			}
		}
		if (!statemp.empty()) {
			vec2.push_back(statemp);
			vector<MyClass>().swap(statemp);
			i = 0;
		}
		
		for (std::vector<vector<MyClass>>::iterator it2 = vec2.begin(); it2 != vec2.end(); ++it2)
		{
			stack<char> itemsta;
			vector<int> panduan;
			stack<MyClass> st;//jisuan
			set<int> sc;//输出
			for (std::vector<MyClass>::iterator item = (*it2).begin(); item != (*it2).end(); ++item)
			{
				MyClass ch = *item;
				switch (ch.GetValue()) {
				case '(':
					//入栈
					st.push(ch);
					break;
				case ')': {
					if (st.empty()) {
						continue;
					}
					MyClass left = st.top();
					if ((left.GetValue() == '(')) {
						sc.insert(left.GetIndex());
						sc.insert(ch.GetIndex());
						//匹配，即出栈
						st.pop();
					}
				}
				}
			}
			if (!sc.empty()) {
				shuchu.push_back(sc);
			}
		}
		int max = 0;
		for (std::vector<set<int>>::iterator se = shuchu.begin(); se != shuchu.end(); ++se)
		{
			set<int>::iterator item;
			int pre = -5;
			int maxitem = 0;
			for (item = (*se).begin(); item != (*se).end(); ++item)
			{
				int now = *item;
				if (now - pre <= 1)
				{
					maxitem += 1;
				}
				else
				{

					if (max < maxitem) {
						max = maxitem;
					}
					maxitem = 1;
				}
				pre = now;

			}
			if (max < maxitem) {
				max = maxitem;
			}
		}
		cout << max << endl;
		max = 0;
		shurustr.clear();
		vector<set<int>>().swap(shuchu);
		vector<vector<MyClass>>().swap(vec2);
		str.clear();
	}
	
	
	return 0;
}