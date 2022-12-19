**我他妈服气，大家不想做可能是觉得太繁琐了，其实加减乘除不是问题，直接用上一题的来做就好了，主要是这个中间表达式的存储，既要按次数排序，又要按照字典序排序，同时还要兼顾增删改查的效率问题，数据结构的使用得斟酌。**

## 数据结构如下：

### 多项式中的一项：
typedef int Coefficient;//存系数
typedef multiset<string> Polynomial;//存相乘的每一个word，采用默认排序方法--字典序,由于word有可能相同，所以用multiset

### 多项式：
typedef map<Polynomial, Coefficient,Cmp> Polynomials;
//因为每一项除了系数外都是唯一的，所以可以用map，其中key就是上面的Polynomial，主要是下面的cmp得注意一下

### Cmp如下，确保排序满足题目要求：
```
struct Cmp
{
	bool operator()(const Polynomial &a, const Polynomial&b)const
	{
		if (a.size() < b.size())//次数高的放前面
			return false;
		else if (a.size() > b.size())
			return true;
		else
			return a < b;//次数相同，字典序小的放前面
	}
};
```
### 为了快速查询给定的word对应的值，直接建一个哈希表unordered_map就好
```
unordered_map<string,int>e_value_map;
for (int i = 0; i < evalvars.size(); i++)
{
	e_value_map.insert(pair<string,int>(evalvars[i], evalints[i]));
}
```
### add、sub、multi的实现：
**add**，就是把b中每一个插入到a里面，如果a中有相同key，就系数相加，如果相加结果为0就删掉这一项，如果不为0就直接修改，如果没有相同的key，直接插入就好。
**sub**同理
**multi**其实就是多次调用add
```
void add(Polynomials&a, const Polynomials&b)//把b都放到a里面
	{
		for (auto p : b)
		{
			auto iter = a.find(p.first);
			if (iter == a.end())
			{
				a.insert(p);
			}
			else if(iter->second+p.second==0)
			{
				a.erase(iter);
			}
			else
			{
				iter->second += p.second;
			}
		}
	}

```



# 总结
****数据结构和c++的stl容易还是要熟悉的。****

### 总的代码如下，至于每个字符怎么进栈出栈，这个只要你做完了上一题，肯定会做。
然后代码里面还有一些细节性的东西，比如0怎么处理啊，看代码就好。
```
typedef int Coefficient;
typedef multiset<string> Polynomial;
struct Cmp
{
	bool operator()(const Polynomial &a, const Polynomial&b)const
	{
		if (a.size() < b.size())//次数高的放前面
			return false;
		else if (a.size() > b.size())
			return true;
		else
			return a < b;//次数相同，字典序小的放前面
	}
};
typedef map<Polynomial, Coefficient,Cmp> Polynomials;
typedef pair<string, int> E_Value_Pair;
class Solution {
public:
	vector<string> basicCalculatorIV(string expression, vector<string> &evalvars, vector<int> &evalints) {

		stack<Polynomials>opd;//放操作数
		stack<char>opr;//放运算符
		char c;
		char pre_opr;
		char pre_c='#';
		expression += "#";
		unordered_map<string,int>e_value_map;
		for (int i = 0; i < evalvars.size(); i++)
		{
			e_value_map.insert(pair<string,int>(evalvars[i], evalints[i]));
		}

		//opd.push(Polynomials());
		opr.push('#');
		int max_len = expression.size();

		for (int i = 0; i < max_len; i++)
		{
			c = expression[i];
			pre_opr = opr.top();
			
			if (c == '+'||c=='-'||c==')'||c=='#')//要考虑作为数字的一元运算符
			{
				while(pre_opr == '+' || pre_opr == '-'|| pre_opr == '*' || pre_opr == '/')
				{ 
					opr.pop();
					if(pre_opr=='+')
					{
						auto top = opd.top();
						if (pre_c != '#' && pre_c != '(')//只有在作为二元运算符的时候才考虑
						{
							opd.pop();
							add(opd.top(), top);
						}
					}
					else if (pre_opr == '-')
					{
						auto top = opd.top();
						if (pre_c != '#' && pre_c != '(')//2元运算
						{
							opd.pop();
							sub(opd.top(), top);
						}
						else
						{
							multi(opd.top(), Polynomials{ {Polynomial{""},-1} });//相当于乘上-1
						}
					}
					else if (pre_opr == '*')
					{
						auto top = opd.top();
						opd.pop();
						multi(opd.top(), top);
					}
					else if (pre_opr == '/')
					{
						auto top = opd.top();
						opd.pop();
						div(opd.top(), top);
					}
					pre_opr = opr.top();
				}
				if (pre_opr == '('&&c==')')
					opr.pop();
				else
					opr.push(c);
			}
			else if (c == '*' || c == '/' )
			{
				while ( pre_opr == '*' || pre_opr == '/')
				{
					if (pre_opr == '*')
					{
						auto top = opd.top();
						opd.pop();
						multi(opd.top(), top);
					}
					else if (pre_opr == '/')
					{
						auto top = opd.top();
						opd.pop();
						div(opd.top(), top);
					}
					opr.pop();
					pre_opr = opr.top();
				}
					opr.push(c);
			}
			else if (c >= '0'&&c <= '9')//常数项作为空串
			{
				int start = i;
				int len = 0;
				for (; i < max_len&&expression[i] >= '0'&&expression[i] <= '9'; i++, len++);
				string str = expression.substr(start, len);
				int num;
				sscanf(str.c_str(), "%d", &num);
				//if(num!=0)
					opd.push(Polynomials{ {Polynomial(),num} });//常数项不应该设为0
				i--;

			}
			else if (c >= 'a'&&c <= 'z')//处理单个表达式
			{
				int start = i;
				int len = 0;
				for (; i < max_len&&expression[i] >= 'a'&&expression[i] <= 'z'; i++, len++);
				string name = expression.substr(start, len);
				unordered_map<string, int>Num;
				auto iter = e_value_map.find(name);
				if (iter == e_value_map.end())//非常数项
				{
					opd.push(Polynomials{ {Polynomial{name},1} });
				}
				else//在 当作常数项
				{
					//if(iter->second!=0)
						opd.push(Polynomials{ {Polynomial(),iter->second} });
				}
				i--;

			}
			else if (c == '(')
			{
				opr.push('(');
				//opd.push(Polynomials());
			}
			if (c!=' ')
				pre_c = c;
		}
		//print(opd.top());
		if (opd.empty())
			return vector<string>();
		else 
			return get_result(opd.top());
	}
	void add(Polynomials&a, const Polynomials&b)//把b都放到a里面
	{
		for (auto p : b)
		{
			auto iter = a.find(p.first);
			if (iter == a.end())
			{
				a.insert(p);
			}
			else if(iter->second+p.second==0)
			{
				a.erase(iter);
			}
			else
			{
				iter->second += p.second;
			}
		}
	}

	void sub(Polynomials&a, const Polynomials&b)
	{
		for (auto p : b)
		{
			auto iter = a.find(p.first);
			if (iter == a.end())
			{
				p.second = -p.second;
				a.insert(p);
			}
			else if (iter->second - p.second == 0)
			{
				a.erase(iter);
			}
			else
			{
				iter->second -= p.second;
			}
		}
	}
	void multi(Polynomials&a, const Polynomials&b)
	{
		Polynomials ret;
		for (auto pb : b)
		{
			if (pb.second == 0)
				continue;
			for (auto pa : a)
			{
				if (pa.second == 0)
					continue;
				Coefficient co = pa.second*pb.second;
				Polynomial tmp = pa.first;
				//merge 函数时c++17的，所以得自己实现
				for (auto word : pb.first)
				{
					tmp.insert(word);
				}
				
				add(ret, Polynomials{ {tmp,co} });
			}
		}
		a=ret;//貌似也不是很复杂嘛？搞错了
	}
	void div(Polynomials&a, const Polynomials&b)
	{
		Polynomials ret;
		for (auto p : b)
		{
			Polynomials tmp{ p };
			add(ret, tmp);
		}
		a = ret;//貌似也不是很复杂嘛？
	}
	void print(Polynomials&ps)
	{
		for (auto p : ps)
		{
			cout << p.second;
			for (auto little_p : p.first)
			{
				cout << "*" << little_p.c_str();
			}
				
			cout << endl;
		}
	}
	vector<string> get_result(Polynomials&ps)
	{
//这里仔细看一下对0的处理，你可能纳闷了，加减乘不是处理了0的问题了吗，
//但是还有一个问题，你直接读入一个0或者某个word的值是0，
//你就会插入到栈里面，我试过不插入，但好麻烦，所以我直接在最后处理好了。
		vector<string> ret;
		for (auto p : ps)
		{
			string line;
			//cout << p.second;
			if(p.second!=0)
				line +=to_string(p.second);
			for (auto little_p : p.first)
			{
				//cout << "*" << little_p.c_str();
				line += "*" + little_p;
			}
			if(!line.empty())
				ret.push_back(line);
			//cout << endl;
		}
		return ret;
	}
	
};
```