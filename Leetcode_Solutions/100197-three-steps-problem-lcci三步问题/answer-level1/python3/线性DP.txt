### 解题思路
dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000007

### 代码

```python3
class Solution:
    def waysToStep(self, n: int) -> int:
        if n==1:
            return 1
        elif n==2:
            return 2
        elif n==3:
            return 4
        dp = [float('-inf') for _ in range(n+1)]
        dp[0]=0
        dp[1]=1
        dp[2]=2
        dp[3]=4
        for i in range(4,n+1):
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000007
        return dp[n]

        
        
```