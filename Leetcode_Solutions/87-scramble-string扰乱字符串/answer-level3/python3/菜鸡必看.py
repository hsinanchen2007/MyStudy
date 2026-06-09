```
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if len(s1)!=len(s2) :
            return False
        n=len(s1)
        dp=[[[None]*(n+1) for _ in range(n)] for _ in range(n)]
        for i in range(n) :
            for j in range(n):
                if s1[i]==s2[j] :
                    dp[i][j][1]=True
        for k in range(2,n+1) :
            for i in range(n-k+1) :   
                for j in range(n-k+1) :
                    dp[i][j][k]=False
                    for w in range(1,k) :
                        if dp[i][j][w] and dp[i+w][j+w][k-w] :
                            dp[i][j][k]=True
                            break
                    for w in range(1,k) :
                        if dp[i][j+k-w][w] and dp[i+w][j][k-w] :
                            dp[i][j][k]=True
                            break
        return dp[0][0][n]
```
