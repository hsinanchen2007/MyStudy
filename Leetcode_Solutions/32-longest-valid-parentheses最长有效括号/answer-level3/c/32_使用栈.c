```
class Solution {

	typedef struct {
		char ch;
		int index;
	} elem;

public :

	int longestValidParentheses(string s)
	{
		int len = s.length();
		stack<elem> stk;
		bool *flag = new bool[len]{};
		
		stk.push({s[0], 0});
		for (int i = 1; i < len; ++i)
		{
			char top = stk.empty() ? '\0' : stk.top().ch, tmp = s[i];
			if (top == '(' && tmp == ')')
			{
				flag[stk.top().index] = 1;
				flag[i] = 1;
				stk.pop();
			}
			else
				stk.push({tmp, i});
		}

		int max = 0, flow = 0;
		int i = 0, j = 0;
		while (i < len)
		{
			for (j = i; j < len; ++j)
			{
				if (flag[j] == 1) ++flow;
				else break;
			}
			if (flow > max) max = flow;
			flow = 0;
			i = j + 1;
		}

		return max;
	}
};
```
