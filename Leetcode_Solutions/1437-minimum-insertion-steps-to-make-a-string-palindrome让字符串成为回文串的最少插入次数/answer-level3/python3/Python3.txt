```
class Solution:
    def minInsertions(self, s: str) -> int:
        def solve(a,b,dp,s):
            if dp[a][b] >= 0:
                return dp[a][b]
            else:
                if s[a] == s[b] and a+1 <= b-1:
                    dp[a][b] = min(solve(a+1, b, dp, s)+1, solve(a, b-1, dp, s)+1, solve(a+1, b-1, dp, s))
                elif s[a] == s[b] and a == b-1:
                    dp[a][b] = 0
                else:
                    dp[a][b] = min(solve(a+1, b, dp, s)+1, solve(a, b-1, dp, s)+1)
                return dp[a][b]
        
        l = len(s)
        dp = [[-1 for i in range(l)] for j in range(l)]
        for i in range(l):
            dp[i][i] = 0
        return solve(0,l-1,dp, s)
```
