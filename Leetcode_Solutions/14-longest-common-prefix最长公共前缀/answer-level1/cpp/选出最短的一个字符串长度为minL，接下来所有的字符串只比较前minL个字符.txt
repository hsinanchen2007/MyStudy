### 解题思路
	  基本思路是，选出最短的一个字符串maxL，长度为minL，接下来所有的字符串只比较前minL个字符。
	  获取最短字符串的方法是把长度和位置存到一个map容器，根据键值自动排序后，选第一个。
	  默认最长公共前缀为最短的那个字符串MaxL，与vector容器中挨个比较。一旦检测到不匹配的位置，说明在
	此位置以前都是公共相同的，将这部分取出，更新maxL。
	  解法很基础。。。然后内存也占用挺多的。。。菜鸡敬上，欢迎指正
### 代码

```cpp
class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		multimap<int, int> m;
		for (int it = 0; it < strs.size(); it++)
		{
			m.insert(make_pair(strs[it].length() ,it));
		}
		multimap<int, int>::iterator mit = m.begin();
		int minL = mit->first;
		string maxL = strs[mit->second];
		for (vector<string>::iterator itt = strs.begin(); itt != strs.end(); itt++)
		{
			for (int j = 0; j < minL; j++)
			{
				if ((*itt)[j] != maxL[j])
				{
					maxL = (*itt).substr(0, j);
                    break;
				}

			}
		}
		return maxL;
	}
};
```