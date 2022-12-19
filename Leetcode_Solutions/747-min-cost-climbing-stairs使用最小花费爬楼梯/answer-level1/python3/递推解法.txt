### 解题思路
思路： 递推解法，类似于斐波那契数列

### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:

        dp = [0 for _ in range(len(cost)+1)]

        for i in range(2, len(cost)+1):
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
        return dp[len(cost)]
```