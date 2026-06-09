```
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        inf = len(days) * costs[2]
        dp = [inf for _ in range(len(days) + 1)]
        dp[0] = 0
        for i in range(1, len(days) + 1):
            dp[i] = min(dp[i], dp[i - 1] + min(costs))
            for j in range(1, i - 1):
                if days[i - 1] - days[j - 1] < 7:
                    dp[i] = min(dp[i], dp[j - 1] + costs[1])
                elif days[i - 1] - days[j - 1] < 30:
                    dp[i] = min(dp[i], dp[j - 1] + costs[2])
        return dp[-1]
```
