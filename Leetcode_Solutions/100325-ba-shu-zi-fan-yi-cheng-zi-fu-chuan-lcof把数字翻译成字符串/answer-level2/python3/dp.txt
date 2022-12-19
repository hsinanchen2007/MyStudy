```
class Solution:
    def translateNum(self, num: int) -> int:
        num = str(num)
        n = len(num)
        if n == 0: return 0
        if n == 1: return 1
        dp = [0]*(n+1)
        dp[0] = 1
        dp[1] = 1  
        for i in range(2,n+1):
            temp = (int(num[i-2]))*10 + int(num[i-1])
            if 9 < temp <= 25:
                dp[i] = dp[i-1] + dp[i-2]
            else:
                dp[i] = dp[i-1]
        return dp[-1]
            
```
