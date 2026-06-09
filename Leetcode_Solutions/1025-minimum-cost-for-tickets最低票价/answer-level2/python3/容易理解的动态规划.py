```
class Solution:
    def mincostTickets(self, days: list, costs: list) -> int:
        #dp[i]是直到第i天的累积票价
        dp = [0] * len(days)
        #边界条件
        dp[0] = min(costs)
        for k in range(1, len(dp)):
            #所买票 满足1天
            tmp_costs_1 = dp[k-1] + min(costs)
            #所买票 满足7天
            tmp = 0
            for p in range(k):
                if days[k]-days[p] >= 7:
                    tmp = dp[p] #7天票覆盖不到的那些天，使用已经解决过的dp，是赋值=，而不是+=，因为dp本来就是累加的
            tmp_costs_7 = tmp + min(costs[1], costs[2])
            #所买票 满足30天
            tmp = 0
            for p in range(k):
                if days[k]-days[p] >= 30:
                    tmp = dp[p]
            tmp_costs_30 = tmp + costs[2]

            dp[k] = min(tmp_costs_1, tmp_costs_7, tmp_costs_30)
        
        return dp[-1]
```
