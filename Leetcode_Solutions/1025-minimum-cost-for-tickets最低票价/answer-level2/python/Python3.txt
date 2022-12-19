![image.png](https://pic.leetcode-cn.com/2d1988bf414f3b7389acb7c6f76c78d717b7abdf08d35bdff624b821603d8571-image.png)


```python3
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [0] * (1+days[-1])
        persist = [1,7,30]
        days_set = set(days)
        for index_dp in range(1,len(dp)):
            if index_dp not in days_set:
                dp[index_dp] = dp[index_dp-1]
                continue
            min_cost = dp[index_dp-1]+costs[0]
            for i in range(1,3):
                temp_cost = costs[i] if index_dp<persist[i] else (dp[index_dp-persist[i]] + costs[i])
                min_cost = temp_cost if min_cost > temp_cost else min_cost
            dp[index_dp] = min_cost
        return dp[-1]
```
