![image.png](https://pic.leetcode-cn.com/6cb1901bb51e9e449218c5c61ba700c81eb9922aa1798292aaeb8513f674e2c6-image.png)
动态规划：
分两种情况
![image.png](https://pic.leetcode-cn.com/3427e8053429d41556b9fed04daa16b4d4d6241ca86411b6037609a0d9c92e7a-image.png)
``` c++
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int maxLen = 0;
        for (int i=1; i<s.size(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(')  {
                    if (i >= 2) dp[i] = dp[i-2] + 2;
                    else dp[i] = 2;
                } else if (i - dp[i-1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    if (i - dp[i - 1] >= 2) {
                        dp[i] = dp[i - dp[i-1] - 2] + dp[i-1] + 2;
                    } else {
                        dp[i] = dp[i-1] + 2;
                    }
                }
                maxLen = max(maxLen, dp[i]);
            } 
        }
        return maxLen;
    }
};
```

