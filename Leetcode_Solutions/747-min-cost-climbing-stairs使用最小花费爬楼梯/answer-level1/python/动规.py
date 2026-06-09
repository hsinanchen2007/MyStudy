### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0] * len(cost)
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in range(2, len(cost)):
            if i == len(cost) - 1:
                dp[i] = min(dp[i - 2] + cost[i], dp[i - 1])
            else:
                dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i])
        return dp[-1]
```