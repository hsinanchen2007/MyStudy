![596b7150094c969f04473e2630d5d4b.png](https://pic.leetcode-cn.com/0302e8ddba5155b426170758a1c8eba340f260fccf756c1e25ac72ef3ee170fd-596b7150094c969f04473e2630d5d4b.png)
用栈就完事了，第一次做出来这种结果。代码贴出来了，当然写的很烂，不喜勿喷。
```
class Solution {
public:
bool isValid(string s) {
	if (!s.size())return 1;
	if (s.size() % 2)return 0;				//有效字符串长度必为偶数
	stack<char> st;
	st.push(s[0]);
	for(int i=1;i<s.size();i++)
	{
		if (st.empty())				//栈为空，则push
		{
			st.push(s[i]);
			continue;
		}
		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
		{
			st.push(s[i]);
			continue;
		}
		if (s[i] == '}' || s[i] == ')' || s[i] == ']')
		{
			if (s[i] == '}' && st.top() == '{')
			{
				st.pop();
				continue;
			}
			else if (s[i] == ']' && st.top() == '[')
			{
				st.pop();
				continue;
			}
			else if (s[i] == ')' && st.top() == '(')
			{
				st.pop();
				continue;
			}
			else return false;
		}

	}
	if(st.empty())return true;
    else return false;

}
};
```

