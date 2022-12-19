### 解题思路
注意边界条件

### 代码

```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # dp
        dp = [0 for i in range(len(s))]
        if len(s) == 0:
            return 0
        for i in range(1,len(s)):
            if s[i] == ")":
                if s[i - 1] == "(":
                    if i >= 2:
                        dp[i] = dp[i - 2] + 2  
                    else:
                        dp[i] = 2
                elif i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == "(":
                    if i - dp[i - 1] >= 2:
                        dp[i] =  dp[i - 1] + dp[i - dp[i - 1] - 2] + 2
                    else:
                        dp[i] = dp[i - 1] + 2    
        return max(dp)
```