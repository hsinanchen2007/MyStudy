```python
class Solution:
    def minCut(self, s: str) -> int:
        l = len(s)
        dp = [x for x in range(-1, len(s))]
        for i in range(l):
            pre, rev = '', ''
            for j in range(i, len(s)):
                pre += s[j]
                rev = s[j] + rev
                if pre == rev:
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1)
        return dp[-1]
       
```