### 解题思路
dp[i]表示走到i层所需的最小代价 
dp[i] = min(dp[i-1]+cost[i] , dp[i-2]+cost[i]) 
最后通往楼顶的选择只有两种，一种是从cost[-1]上去，另一种是从cost[-2]上去

### 代码

```python
class Solution(object):
    def minCostClimbingStairs(self, cost):
        dp = [0 for _ in range(len(cost))]
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in range(2,len(cost)):
            dp[i] = min(dp[i-1]+cost[i] , dp[i-2]+cost[i])
        return min(dp[-1],dp[-2])

```