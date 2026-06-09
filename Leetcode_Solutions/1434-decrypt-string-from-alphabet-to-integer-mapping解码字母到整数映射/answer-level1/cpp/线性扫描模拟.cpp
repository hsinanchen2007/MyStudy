#### 线性扫描模拟
 - 从左到右遍历
 - 如果是数字，则转成相应小写字母`'a'~'i'`
 - 如果是`'#'`，则删除结果中最后两个小写字母，然后转成相应的小写字母`'j'~'z'`
```
class Solution {
public:
	string freqAlphabets(string s) {
		string ans;
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (s[i] == '#')
			{
				if (i >= 2)
				{
					int nPreNum = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
					if (nPreNum >= 10 && nPreNum <= 26)
					{
						ans.erase(ans.size() - 2);
						ans.push_back('j' + nPreNum - 10);
					}
				}
			}
			else
			{
				ans.push_back('a' + s[i] - '1');
			}
		}

		return ans;
	}
};
```
