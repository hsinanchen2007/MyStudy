这题只要把S中的有效括号全都去掉，剩下的括号数就是要补的最少括号数了。而去有效括号，只要把S放进栈中就好。
```
class Solution {
public:
	int minAddToMakeValid(string S) {
		stack<char> st;
		for (int i = 0; i < S.length(); i++) {
			if (S[i] == '(')
				st.push('(');
			else if (!st.empty() && st.top() == '(')
				st.pop();
			else
				st.push(')');
		}
		return st.size();
	}
};
```
