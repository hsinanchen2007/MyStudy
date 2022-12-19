### 思路
1. 读懂题意，确定要找的子串符合前半和后半一样。
2. 确定字符串比较方法，使用`memcmp()`
3. 暴力

### 答题
```C++
int distinctEchoSubstrings(string text)
{
	unordered_set<string> ans;
	const char* t = text.c_str();
	for (size_t i = 0; i < text.size(); i++)
	{
		for (size_t j = 1; i + 2 * j <= text.size(); j++)
		{
			if (memcmp(t + i, t + i + j, j) == 0)
			{
				ans.insert(text.substr(i, j));
			}
		}
	}
	return (int)ans.size();
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

