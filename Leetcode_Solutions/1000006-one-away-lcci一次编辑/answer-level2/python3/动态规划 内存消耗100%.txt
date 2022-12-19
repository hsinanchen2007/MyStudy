```
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if abs(len(first)-len(second))>1: return False
        dp = [[0 for _ in range(len(second)+1)] for _ in range(len(first)+1)]
        for i in range(len(second)+1):
            dp[0][i] = i
        for i in range(len(first)+1):
            dp[i][0] = i
        for i in range(1, len(first)+1):
            for j in range(1, len(second)+1):
                if first[i-1]==second[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
        
        return dp[-1][-1]<2
```
