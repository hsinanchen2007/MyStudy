```
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        
        n = len(s)
        if n<=1 or len(set(s))==1:
            return n
       
        dp = [[0 for j in range(n) ]for i in range(n)]
        dp[n-1][n-1]=1
        for l in range(n-2,-1,-1):
            dp[l][l]=1
            for r in range(l+1,n):
                if s[l]==s[r]:
                    dp[l][r] = dp[l+1][r-1]+2
                else:
                    dp[l][r] = max([dp[l+1][r],dp[l][r-1]])
                    
        return dp[0][n-1]
                    
        
```
