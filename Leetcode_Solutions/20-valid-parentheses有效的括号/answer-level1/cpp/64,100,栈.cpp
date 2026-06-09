### 解题思路
注意陷阱，考虑到"["与"]"的情况

### 代码

```cpp
class Solution {
public:
	bool isValid(string s) {
		stack<char> ls;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				ls.push(s[i]);
			else
			{
				if (ls.size() == 0)
					return false;
				if ((s[i] == ')'&&ls.top() != '(') ||
					(s[i] == ']'&&ls.top() != '[') ||
					(s[i] == '}'&&ls.top() != '{'))
					return false;
				ls.pop();	
			}
		}
		//个数不匹配
		if (ls.size() > 0)
			return false;
		return true;
	}
};

```