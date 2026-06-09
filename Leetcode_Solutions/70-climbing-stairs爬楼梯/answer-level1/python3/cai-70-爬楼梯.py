### 解题思路
动态规划实现

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:return 1
        dp = [0 for _ in range(n + 1)]
        dp[1], dp[2] = 1, 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]



```