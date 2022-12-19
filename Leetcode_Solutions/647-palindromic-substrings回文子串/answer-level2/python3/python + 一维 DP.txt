```python
class Solution:
    def countSubstrings(self, s: str) -> int:
        l, cnt = len(s), 0
        dp = [0] * l 
        for i in range(l - 1, -1, -1):
            pre = 0
            for j in range(i, l):
                temp = dp[j]
                if i == j: dp[j] = 1
                elif j == i + 1: dp[j] = 1 if s[i] == s[j] else 0
                elif s[i] == s[j]: dp[j] = pre
                elif s[i] != s[j]: dp[j] = 0
                pre = temp
                cnt += dp[j]
        return cnt
```