计算逻辑和256.刷房子一致，这里在考虑每一个房子时，先计算出上一行最小的花费以及其下标，再计算第二小的花费。

在考虑颜色时，如果颜色的下标是上一行最小化费的下标，则花费加上一行第二小的花费，否则直接加最小的花费。
```
class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        l = len(costs)
        if(l==0): return 0
        if(l==1): return min(costs[0])
        
        k = len(costs[0])
        dp = [k*[0] for _ in range(l+1)]

        for i in range(1,l+1):
            min_1 = min(dp[i-1][:])
            j_1 = dp[i-1][:].index(min_1)

            min_2 = sorted(dp[i-1][:])[1]
            for j in range(k):
                dp[i][j] = costs[i-1][j] + (min_1 if j!=j_1 else min_2)
        
        return min(dp[-1][:])

```
