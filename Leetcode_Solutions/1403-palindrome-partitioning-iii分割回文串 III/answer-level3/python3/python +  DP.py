```python
class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        if k >= len(s): return 0
        l = len(s)
        cost =  [[0] * l for _ in range(l)]
        for i in range(l - 1, -1, -1):
            for j in range(i + 1, l):
                cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j])
        dp = [[float('inf')] * k for _ in range(l)]
        for t in range(k):
            for i in range(l):
                if t == 0:
                    dp[i][t] = cost[0][i]
                    continue
                for j in range(i):
                    dp[i][t] = min(dp[j][t - 1] + cost[j + 1][i], dp[i][t])
        
        return dp[-1][-1]
```