思路：
step-1:先构造不大于n的完全平方数list
step2:dp更新，如果这个数本身就是完全平方数那么等于1，不然dp[i] = 1+min([dp[i-k] for k in totallist if i-k>0])
```python
import numpy as np
class Solution:
    def numSquares(self, n: int) -> int:
        #step-1:先构造不大于n的完全平方数list
        totallist= [i**2 for i in range(1,int(np.sqrt(n))+1)]
        #step2:dp更新，如果这个数本身就是完全平方数那么等于一，不然dp[i] = 1+min([dp[i-k] for k in totallist if i-k>0])
        dp = [1]*(n+1)
        for i in range(2,n+1):
            if i in totallist:
                dp[i]=1
            else:
                dp[i] = 1+min([dp[i-k] for k in totallist if i-k>0])
        return(dp[-1])
```
