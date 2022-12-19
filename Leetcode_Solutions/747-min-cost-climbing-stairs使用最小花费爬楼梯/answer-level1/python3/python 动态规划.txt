### 解题思路
转移方程 dp[i]=cost[i]+min(dp[i-1],dp[i-2])
需要注意的一点是最后返回的是dp[n-1]和dp[n-2]中最小的，这两个地方都可以直接达到楼顶，这里隐含了楼顶的cost是零

### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n=len(cost)
        dp=[0]*n
        dp[0]=cost[0]
        dp[1]=cost[1]
        for i in range(2,n):
            dp[i]=cost[i]+min(dp[i-1],dp[i-2])
        return min(dp[n-1],dp[n-2])   
```