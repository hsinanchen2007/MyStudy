### 解题思路
可遍历的完全平方数的范围在[1,sqrt(n)]之间，n时，最多的组成个数是n(n个1)

### 代码

```python
class Solution(object):
    def numSquares(self, n):
        dp = [i for i in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,int(i**0.5)+1):
                dp[i] = min(dp[i],dp[i-j*j]+1)
        return dp[n]
```