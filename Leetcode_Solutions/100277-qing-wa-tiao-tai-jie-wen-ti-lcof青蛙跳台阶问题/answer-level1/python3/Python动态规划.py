### 解题思路
和斐波那契数列基本一致（第一个值不同）

### 代码

```python3
class Solution:
    def numWays(self, n: int) -> int:
        dp = {}
        dp[0] = 1
        dp[1] = 1
        if n > 1:
            for i in range(2,n+1):
                dp[i] = dp[i-1] + dp[i-2]
                
        return dp[n]%1000000007
```