回溯终结条件：
1.树的深度 == 4 或者说 ip已经分成了4段；
2.当前串已经用完了；
需同时满足1.2.

回溯剪枝条件：
1.子串长度要 属于 [4 - depth, 12 - 3*depth]；
2.当前子串(IP段)的值要 属于 [0, 255] 且 该IP段数字位数大于1时，不能数字0开始；
3.树的深度 == 4时，串还没用完，剪掉。

```
class Solution {
public:
	vector<string> res;

	bool isValid(const string& tmp)
	{
		if (tmp[0] == '0' && tmp.size() > 1)  return false;

		int num = stoi(tmp);
		if (0 <= num && num <= 255) return true;
		else return false;
	}

	void dfs(string& s, int depth, vector<string>& tmp)
	{
       	// 树深剪枝
		if (depth == 4 && s.size() != 0)	return;

    	// 合并结果串(IP段)
		if (depth == 4 && s.size() == 0)
		{
			string a;
			for (int i = 0; i < 4; ++i)
			{
				a += i != 3 ? tmp[i] + "." : tmp[i];
			}
			res.push_back(a);
			return;
		}

		// 长度剪枝
		if (s.size() < 4 - depth || s.size() > 12 - 3 * depth)   return;

		for (int i = 1; i <= 3; ++i)
		{
			if (i > s.size())	continue;

			// 当前子串(IP段)剪枝
			string subStr = s.substr(0, i);
			if (isValid(subStr))
			{
				tmp.push_back(subStr);
				string leftStr = s.substr(i);

				dfs(leftStr, depth + 1, tmp);
				tmp.pop_back();
			}
		}
	}
public:
	vector<string> restoreIpAddresses(string s)
	{
		if (s.size() < 4 || s.size() > 12)  return {};

		vector<string> tmp;
		dfs(s, 0, tmp);

		return res;
	}
};
```

涉及API：
string.substr(pos, count)
pos: 起始位置，0为起始位置
count：表示子串长度

stoi (since C++11)
string类型转int类型

详细可以去https://en.cppreference.com/上看