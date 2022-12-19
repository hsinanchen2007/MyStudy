### 动态规划

时间复杂度O(n)， 空间复杂度O(l)。基本上都是击败95%以上的用户，大家可以参考一下。

1. 初始状态：dp[0] = cost[0], dp[1] = cost[1]

2. 状态转移方程： dp[i] = min(dp[i-1],dp[i-2]) + cost[i]

3. 实际上是求到最后一个楼梯的下一个楼梯需要多少体力。

代码如下：
```
class Solution:
    # dp[i] = min(dp[i-1],dp[i-2])+cost[i]
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        if n==2:
            return min(cost)
        
        p = cost[0]
        q = cost[1]
        for i in range(2,n):
            next_ = min(p,q) + cost[i]
            p = q
            q = next_  
        return min(p,q)
        
        
```