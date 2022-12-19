### 解题思路
这题涉及最长子串长度，考虑用动态规划。具体如何更新dp[i]，详细分析即可。

### 代码

```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if not s:
            return 0
        length = len(s)
        dp = [0]*length
        for i in range(1,length):
            if s[i]==')' and i-1-dp[i-1]>=0 and s[i-1-dp[i-1]]=='(':
                dp[i]=dp[i-1]+dp[i-2-dp[i-1]]+2
        return max(dp)
```