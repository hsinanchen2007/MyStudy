### 解题思路
根据官方的第一个题解的思路实现的，先假设strs[0]为公共前缀，之后遍历1-strs.size()的字符串，判断是否含有prefix，如果不含有prefix，则将prefix长度减1，再次判断prefix-1是否为其子串（==0表示含有该字串），直到prefix为空，感觉官方思路很赞，另外可以通过双指针的方式实现

### 代码

```cpp
class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";//strs无字符串，则为空
		string prefix = strs[0];//假设第一个字符串为公共前缀
		for (int i=1;i<strs.size();i++)//判断每一个字符串中是否含有prefix，
		{
			while (strs[i].find(prefix)!=0)//如果不含有prefix，则将prefix长度减1，再次判断prefix-1是否为其子串（==0表示含有该字串），直到prefix为空，
			{
				if (prefix == "") return "";//如果prefix为空串，则说明公共前缀为空
				prefix = prefix.substr(0, prefix.length() - 1);
			}
		}
		return prefix;
	}
};
```