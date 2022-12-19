### 解题思路
类似于爬楼梯问题，注意最后返回min(dp[-1],dp[-2]),时间和内存beat 99%、98%

### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if not cost:
            return 0
        n = len(cost)
        # 创建数组
        dp = [0] * n
        # 初始化数组
        dp[0] = cost[0]
        dp[1] = cost[1]
        # 填充其他位置
        for i in range(2, n):
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i]
        return min(dp[-2],dp[-1])
        
```