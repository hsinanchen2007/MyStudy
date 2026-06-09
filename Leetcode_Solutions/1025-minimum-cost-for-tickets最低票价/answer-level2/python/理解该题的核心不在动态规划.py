动态规划的转移方程没什么好说的，一眼就能看明白。但是为什么是这个转移方程呢？很多题解都没有提到，需要按照贪心策略去推导转移方程。

第i天不出行，那么第i天可以什么也不干，也可以买任意一种票，但是最优解肯定是什么也不干，延续第i - 1天的花费。
第i天要出行，那么第i天必然要有票。表面上看取决于前几天是不是有7天票，30天票，但是到底取决于哪一天？按照贪心原则，为了让当天的花费平均成本最低，那么7天票最好是就在7天前买的，30天票就是30天买的，还有一种就是当天直接买一张一天票。这三个选择选个最小的值就是推导值，这也是转移方程的得来。


```
class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        days_set = set(days)
        max_day = days[-1]
        dp = [0] * (max_day + 1)
        for i in range(1, max_day + 1):
            if i not in days_set:
                dp[i] = dp[i - 1]
            else:
                dp_7 = 0 if i - 7 < 0 else dp[i - 7]
                dp_30 = 0 if i - 30 < 0 else dp[i - 30]
                dp[i] = min(dp[i - 1] + costs[0],
                            dp_7 + costs[1],
                            dp_30 + costs[2])

        return dp[-1]
```
