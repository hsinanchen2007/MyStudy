```
class Solution:
    def divisorGame(self, N: int) -> bool:
        dp = [0 for i in range(N+1)]
        dp[1] = 0
        if N<=1:
            return False
        else:
            dp[2]= 1
            for i in range(3,N+1):
                for j in range(1,i):
                    if i%j==0 and dp[j]==1:
                        dp[i]=1
            
            return dp[N]==1
```
