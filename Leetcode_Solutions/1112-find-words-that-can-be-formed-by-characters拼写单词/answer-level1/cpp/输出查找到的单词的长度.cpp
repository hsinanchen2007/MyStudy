### 解题思路
循环词汇表，对词汇表中的每一个单词进行分析
循环词汇表中单词的每一个字符，去字母表中查找，查找到符合的字母以后需要从字母表中删除
（查找到某个字母所在的位置是pos，那就要把pos的这个位置剔除掉），循环过程中发现没有找到
这个字母那就循环下一个，假如都能找到那循环次数肯定就等于字符串的长度了

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
	vector<string> vecres;
	int res = 0;
	for (int i = 0; i < words.size(); i++)
	{
		string str = words[i];
		if (chars.length() < str.length())
		{
			continue;
		}
		string checks = chars;
		int j = 0;
		for (j; j < str.length(); j++)
		{
			char ch = str[j];
			size_t pos = checks.find(ch);
			if (pos == string::npos) {
				break;
			}
			else
			{
				if (pos != 0) {
					checks = checks.substr(0, pos) + checks.substr(pos+1);
				}
				else 
				{
					checks = checks.substr(pos+1);
				}
			}
		}
		if (j == str.length())
		{
			res += str.length();
		}
	}
	return res;
}
};
```