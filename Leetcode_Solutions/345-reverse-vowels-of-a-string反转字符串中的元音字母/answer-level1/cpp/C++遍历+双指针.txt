### 解题思路
此处撰写解题思路
1. 遍历字符串，记录元音字母的索引值；
2. 交换首尾索引值对应的字符串，继续依次向内交换；
### 代码

```cpp
class Solution
{
public:
	string reverseVowels(string s)
	{
		vector<int> index;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
				|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
			{
				index.push_back(i);
			}
		}

		for (int j = 0; j < index.size() / 2; j++)
		{
			swap(s[index[j]], s[index[index.size() - 1 - j]]);
		}
		
		return s;
	}
};
```