### 解题思路
一开始卡在28测例，发现判断的条件出错了。
	思路：
	将字符串数组按长度进行排序，长的字符串不可能是短的字符串的后缀子串，然后判断是否目前处理的字符串是之前处理的字符串的子串，如果不是，加进处理的字符串中即可。

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

bool Cmp(const string &s1, const string &s2)
{
	return s1.length() > s2.length();
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
    	sort(words.begin(), words.end(), Cmp);
    	string temp = "";
    	int res = 0;
    	for (auto s : words)
    		if ((int)temp.find(s + "#") == -1)
    			temp += s + "#";

    	return temp.length();
    }
};
```