如果当天不出行，总成本等于前一天，否则动态规划找到最小值。

```
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        max_d = days[len(days)-1]
        dp = [0] * (max_d+1)
        for i in range(1, max_d+1):
            if i not in days:
                dp[i] = dp[i-1]
            else:
                dp[i] = min(dp[i-1] + costs[0], dp[max(0, i-7)] + costs[1], dp[max(0, i-30)] + costs[2])
        return dp[max_d]
```
