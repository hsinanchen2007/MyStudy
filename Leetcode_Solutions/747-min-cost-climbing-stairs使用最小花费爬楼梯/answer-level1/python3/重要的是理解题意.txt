
清晰的理解：题意是要到达楼层顶部，这不同于到达最后一个阶梯；这其中隐含条件是到达楼层顶部是不需要体力花费值的；
理解了这一点就能明白示例1中的结果为什么是15而不是15+20。
解题思路：从地面可以直接越向第0，1阶梯：`dp[0] = cost[0]`，`dp[1] = cost[1]`，对于跨到第2阶梯，可以从第0阶跨两步，耗费`dp[0]+cost[2]`；或者从第1阶跨一步 ，耗费dp[1]+cost[2]；所以对于跨到第n阶，可以从第`dp[n-2]`跨两步，也可以从`dp[n-1]`跨一步，再耗费cost[n]，求出dp[n-1]和dp[n-2]的最小值就可以得到爬到第n阶的最小耗费值；

状态转移方程：`dp[i] = min(dp[i-1], dp[i-2]) + cost[i]`

最后比较从第n-1阶迈到楼顶的花费和从n-2阶迈到楼顶花费的最小值即可
```
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = dict()
        dp[0] = cost[0]
        dp[1] = cost[1]
        n = len(cost)
        for i in range(2, n):
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i]
        return min(dp[n-1], dp[n-2])
```
