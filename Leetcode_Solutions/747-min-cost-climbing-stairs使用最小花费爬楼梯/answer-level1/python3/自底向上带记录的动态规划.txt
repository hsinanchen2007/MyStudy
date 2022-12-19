### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0 for _ in cost]
        for i, x in enumerate(cost):
            if i <= 1:
                dp[i] = x
            dp[i] = min(dp[i-1] + x,dp[i-2]+x)
        return min(dp[-1],dp[-2])
```