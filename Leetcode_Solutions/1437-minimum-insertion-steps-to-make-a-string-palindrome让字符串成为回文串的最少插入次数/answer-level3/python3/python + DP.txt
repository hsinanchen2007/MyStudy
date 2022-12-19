```python
class Solution:
    def minInsertions(self, s: str) -> int:
        if s == '': return 0
        l = len(s)
        dp = [[0] * l for _ in range(l)]
        for i in range(l - 1, -1, -1):
            for j in range(i + 1, l):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1
        
        return dp[0][-1]
```