### 解题思路
原来叫卡特兰数

### 代码

```python3
class Solution:
    def numTrees(self, n: int) -> int:
        if n == 1:
            return 1
        dp = [1] * (n + 1)
        for i in range(2,n+1):
            res = 0
            for j in range(1,i + 1):
                res += dp[j-1] * dp[i - j]
            dp[i] = res
        return dp[-1]
```