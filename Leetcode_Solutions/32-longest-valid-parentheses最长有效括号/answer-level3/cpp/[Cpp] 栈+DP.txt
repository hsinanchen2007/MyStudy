### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        // // 栈
        // stack<int> st;
        // st.push(-1);
        // int res = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == '(') {
        //         st.push(i);
        //     } else {
        //         st.pop();
        //         if (st.empty()) {
        //             st.push(i);
        //         } else {
        //             int tmp = i - st.top();
        //             res = max(res, tmp);
        //         } 
        //     }
        // }
        // return res;

        // DP
        int res = 0;
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    int tmp = (i > 2 ? dp[i - 2] : 0) + 2;
                    dp[i] = max(dp[i], tmp);
                } else {
                    int num = dp[i - 1];
                    // 前一个位置的左边界不越界
                    // num:i位置和它前面匹配到的'('之间的有效括号的长度
                    // nu:i位置匹配到的'('前面位置连续的有效括号的长度
                    // 再加上i位置的一对括号 2
                    if (i - num - 1 >= 0 && s[i - num - 1] == '(') {
                        int nu = ((i - num - 2) >= 0 ? dp[i - num - 2] : 0);
                        dp[i] = max(dp[i], num + 2 + nu);
                    }
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
```