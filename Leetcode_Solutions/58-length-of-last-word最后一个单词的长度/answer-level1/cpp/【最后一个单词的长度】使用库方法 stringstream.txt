### 思路
1. 先反转字符串。
2. 再使用 `stringstream` 转化单词。
3. 返回第一个单词的长度。

### 答题
```C++
int lengthOfLastWord(string s)
{
	reverse(s.begin(), s.end());
	istringstream ss(s);
	string word;
	while (ss >> word)
	{
		return word.size();
	}
	return 0;
}
```




### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

