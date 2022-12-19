### 思路
1. 要求删除最小数量的字符，那么从删除 0 个开始。
2. 使用`vector<int> use`标志位，表示每次删除的字符。
3. 初始化时，决定删除几个字符。之后循环得到标志位的下一次排列。这样就能遍历删除各个字符组合的情况。
4. 根据标志位，计算括号是否合法。
5. 结果需要去重复，所以使用`set<string> ans`保存。
6. 最后转为输出格式。

### 答题
```C++
bool valid(string& s, vector<int>& use) // 根据use标志位，验证括号是否合法
{
	int st = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (!use[i]) continue;
		st += (s[i] == '(');
		st -= (s[i] == ')');
		if (st < 0) return false;
	}
	return (st == 0);
}

vector<string> removeInvalidParentheses(string s) 
{	
	set<string> ans;
	vector<int> use(s.size(), 1);

	for (int k = 0; k < s.size(); k++)
	{
		for (int i = 0; i < s.size(); i++)  // 第k次寻找，初始化标志位，使前k个字符无效
		{
			use[i] = (i >= k);
		}

		do
		{
			if (valid(s, use))
			{
				string a;   // 拷贝符合要求的字符串
				for (size_t i = 0; i < s.size(); i++)
				{
					if (!use[i]) continue;
					a += s[i];
				}
				ans.insert(a);

				k = s.size();   // 在下一次循环时结束k层的循环，本次循环内的do-while循环继续执行
			}
		} while (next_permutation(use.begin(), use.end())); // 得到标志位的下一个排列
	}
	if (ans.empty()) return { "" };
	return vector<string>(ans.begin(), ans.end());
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

