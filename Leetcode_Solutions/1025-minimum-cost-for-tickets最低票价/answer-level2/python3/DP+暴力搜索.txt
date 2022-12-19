### 解题思路
第i天的最低费用有三种选择：
1.从i-1天;
2.从第j天：分为2中情况：第j天买7天的票；第j天买30天的票，两者取小。
最后取三者最小。

### 代码

```python3
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        if not days or not costs:
            return 

        size = len(days)
        dp = [float('inf')] * (size + 1)
        dp[0]=0
        dp[1] = min(costs)

        for i in range(2, size + 1):
            for j in range(1, i):
                temp = days[i - 1] - days[j - 1]
                dp[i]=min(dp[i], 
                          dp[i - 1] + min(costs),
                          dp[j - 1] + costs[1]*((temp+7)//7),
                          dp[j - 1] + costs[2]*((temp+30)//30))

        return dp[-1]
```