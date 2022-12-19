### 解题思路
暴力枚举

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlength = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i + 1; j < s.size(); j++){
                if(s[i] == '(' && s[j] == ')' && !((j - i + 1) % 2)){
                    if(isValid(string(s, i, j - i + 1)))
                    maxlength = max(maxlength, j - i + 1);
                }
            }
        }
        return maxlength;
    }
    bool isValid(string s) {
		stack<char> st;
		for (auto c : s) {
			if (st.empty()) {
				st.push(c);
			}
			else {
				switch (c) {
				case ')':
					if (st.top() == '(')
						st.pop();
					else st.push(c);
					break;
				case ']':
					if (st.top() == '[')
						st.pop();
					else st.push(c);
					break;
				case '}':
					if (st.top() == '{')
						st.pop();
					else st.push(c);
					break;
				default:
					st.push(c);
					break;
				}
			}
		}
		if (st.empty())
			return true;
		else
			return false;
	}
};
```

### 解题思路
栈的用法

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlength = 0;
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(!st.empty()){
                    maxlength = max(maxlength, i - st.top());
                }
                else{
                    st.push(i);
                }
            }
        }
        return maxlength;
    }
};
```
### 解题思路
动态规划，这道题的状态表达式和状态转移方程不太好找。
dp[i] 是必须以s[i]为结束字符')'的最长有效括号的长度。
dp[i] = dp[i-2] + 2
      = dp[i-1] + 2 + dp[i - dp[i-1] - 2];
### 代码
```

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty() || s.size() == 1){
            return 0;
        }
        int maxLength = 0;
        int dp[s.size()] = {0};
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i] = 2 + ((i >= 2) ? dp[i-2] : 0);
                }
                else if(s[i-1] == ')' && dp[i-1] > 0){
                    if((i - dp[i-1] - 1 >= 0)&&(s[i - dp[i-1] - 1] == '(')){
                        dp[i] = dp[i-1] + 2 + ((i - dp[i-1] - 2 >= 0) ? dp[i - dp[i-1] - 2] : 0);
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};
```
