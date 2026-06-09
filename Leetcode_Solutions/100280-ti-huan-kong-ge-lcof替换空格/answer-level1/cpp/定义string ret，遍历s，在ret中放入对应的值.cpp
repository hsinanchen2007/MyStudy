//定义一个string ret，遍历s，将s[i]放入ret中，
//当s[i]=空格时，将%20放入ret中，
//返回ret
```
class Solution {
public:
	string replaceSpace(string s) {
		string ret = "";
		for (int i = 0; i < s.size();i++)
		{
			if (s[i]==' ')
			{
				ret += "%20";
				continue;
			}
			ret += s[i];
		}
		return ret;
	}
};
```
