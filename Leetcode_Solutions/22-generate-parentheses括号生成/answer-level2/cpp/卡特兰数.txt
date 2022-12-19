### 解题思路
想了许久没想出来，然后看了评论，看到一个前辈用的递归，运行他的结果时发现出来的组合个数刚好是卡特兰数。合法的一个排列从任意位置向前，右括号的个数都要小于等于左括号的个数；而满足了从任意位置向前，右括号个数都小于等于左括号个数并且对于整个排列左括号的个数等于右括号的个数的排列就是合法的。记得有一个题目：有n个人每个人拿着5块钱纸币，还有另外n个人每个人拿着10块钱纸币，这2n个人互相不认识，他们都去自动售货机上买售价为5块的可乐，一开始售货机没有零钱，问这2n个人有多少种排列方式去买可乐。这个题目道理是一样的。


### 代码

```cpp
class Solution {
public:
vector<string> generateParenthesis(int n) {
        return generateParenthesis2(n,n);
    }
vector<string> generateParenthesis2(int n,int m)
{
	vector<string> res;
	if (n == 0 && m == 0)
	{
		res.push_back("");
	}
	if (n != 0 && m == 0)
	{
		string tmp = "";
		for (int i = 0; i < n; i++)
		{
			tmp += "(";
		}
		res.push_back(tmp);
	}
	if (m == n&&m>0&&n>0)
	{
		for (auto s : generateParenthesis2(n, m - 1))
		{
			res.push_back(s + ")");
		}
	}
	else if (n>m&&m>0 && n>0)
	{
		for (auto s : generateParenthesis2(n, m - 1))
		{
			res.push_back(s + ")");
		}
		if (n - 1 >= m)
		{
			for (auto s : generateParenthesis2(n - 1, m))
			{
				res.push_back(s + "(");
			}
		}
	}
	//else if (n < m)
	//{
	//	res.push_back("");
	//}
	return res;
}

};
```