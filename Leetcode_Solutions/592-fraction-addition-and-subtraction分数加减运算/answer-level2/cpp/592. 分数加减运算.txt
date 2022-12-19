### 解题思路
数据先存如pair中 运算符存入op中
pair<int,int> 分子，分母
根据分母经行通分：
如：1/2+1/4
  数据储存：[1,2],[1,4]
  根据分母2，4找到的最小公倍数4
  然后根据最小公倍数经行通分，运算分子
一直循环直到数据处理完

![image.png](https://pic.leetcode-cn.com/afbdf05c09c7e9125671d6fcb0c89487764d401a42677fe13612302053e4356b-image.png)

### 代码

```cpp
class Solution {
public:
    //flg为1：求最小公倍数 flg为0求最大公因数
  int getMin(int a, int b,int flg)
{
	a = abs(a); b = abs(b);
	int x = a, y = b;
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int r = a % b;
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	if (flg == 1)
		return x * y / b;
	else
		return b;
}
//从字符串获取数字
int getNum(int& i, string s)
{
	int num = 0;
	for (; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + s[i] - '0';
		}
		else
		{
			return num;
		}
	}
	return num;
}
//将数据放在data中，将运算符放在op中 分子分母存在pair中
void putNum(string s, vector<pair<int, int>>& data, vector<char>& op)
{

	for (int i = 0; i < s.length(); i++)
	{
		int up,down;
		if (s[i] == '-' && i == 0)
		{
			i++;
			up = -getNum(i, s);
			i++;
			down = getNum(i, s);
			data.push_back(make_pair(up, down));
			
		}
		else
		{
			up = getNum(i, s);
			i++;
			down = getNum(i, s);
			data.push_back(make_pair(up, down));
		}
		op.push_back(s[i]);
	}
}

string fractionAddition(string expression)
{

	vector<pair<int, int>> data;
	vector<char> op;
	putNum(expression, data, op);
	int sum = data[0].first, com=data[0].second,j=0;
	int a1 = sum, b1 = com;//获取分母公因数 然后通分，分子进行运算
	for (int i = 1; i < data.size(); i++)
	{
		int a2 = data[i].first;
		int b2 = data[i].second;
		com = getMin(com, b2,1);
		a1 *= com / b1;
		a2 *= com / b2;
		char p = op[j++];
		if (p == '+')
			sum =a1 +  a2;
		else
			sum =a1- a2;
		a1 = sum;
		b1 = com;
	}//最后将结果转化为字符串
	string res = "";
	if (sum != 0)
	{
		int c = getMin(sum, com, 0);
		sum /= c;
		com /= c;
		string up = to_string(sum);
		string down = to_string(com);
		res += up + "/" + down;
	}
	else
	{
		res = "0/1";
	}
	return res;
}
};
```