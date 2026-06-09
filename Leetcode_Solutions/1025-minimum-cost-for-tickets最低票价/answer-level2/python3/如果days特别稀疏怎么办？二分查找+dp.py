```
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [float('inf')]*len(days)
        diff=[1,7,30]
        for i in range(len(days)):
            for j in range(3):
                index=days[i]-diff[j]
                if index<days[0]:
                    dp[i]=min(dp[i],costs[j])
                    continue
                indexr = bisect.bisect_right(days,index)-1
                dp[i] = min(dp[i],dp[indexr]+costs[j])
        return dp[-1]
```
