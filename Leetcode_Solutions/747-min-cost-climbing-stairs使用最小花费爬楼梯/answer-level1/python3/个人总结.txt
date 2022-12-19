### 解题思路
看了大神的思路才明白，怎么搞，这个题最关键的是，他的状态转移方程和最后输出是不一样的，最后一步，直接用f[i]表示最低花费，f[i] = min{f[i-1], f[i-2]+cost[i]}，意即经过cost[i],不经过cost[i],但这样定义时，f[i-1] 和f[i-2]没法用递推计算，如果表示最低花费，他们各自也要分为经过i-1,(i-2)或者不经过这两种情况，计算时会发现，定义有问题，没法计算；
故改变思路，定义为f[i]表示经过i的最低花费，那么很简单, 最低花费 = min(f[i],f[i-1]),要计算f[i],递推公式可以列为f[i] = min{f[i-1]+cost[i], f[i-2]+cost[i]}, 也就是从i-1一步到i,或者i-2跳两步到i，而已知cost[2,1000], 不用考虑特殊情况，直接递推计算，最终得到所求最低花费。
### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0 for i in range(n)]
        dp[0], dp[1] = cost[0], cost[1]
        for i in range(2, n):
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
        return min(dp[n-1],dp[n-2])
```