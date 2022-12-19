### 解题思路
第一步：给chars建立一个map_chars<char,int>统计字符表中每个字符的个数；
第二步：给words中每一个单词建立map_words<char,int>统计一个单词里面每个字符出现的次数；
第三步：比较map_words中每个字符出现的次数是否小于等于map_chars出现的次数，满足条件就将每个字符出现的次数叠加（即最终就是单词的长度）
第四步：判断叠加的长度是否和当前单词长度一致，一致叠加到返回值中，不一样说明只是单词中部分字符符合条件

整体思维是借鉴解题答案中提示，然后自己转化了一下。如果没有提示，入手还是挺难的，没有头绪。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
	int m = 0;
	map<char, int>map_chars;
	for (int i = 0; i < chars.size(); i++)
		map_chars[chars[i]]++;
	map<char, int>map_words;
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < words[i].size(); j++)
		{
			map_words[words[i][j]]++;
		}
		int temp = 0;
		for (map<char, int>::iterator it = map_words.begin(); it != map_words.end(); it++)
		{
			if (map_chars.find(it->first) != map_chars.end())
			{
				if (map_chars[it->first] >= it->second)
					temp += it->second;
			}
		}
		if (temp == words[i].size())
			m += temp;
		temp = 0;
		map_words.clear();
	}
	return m;
    }
};
```