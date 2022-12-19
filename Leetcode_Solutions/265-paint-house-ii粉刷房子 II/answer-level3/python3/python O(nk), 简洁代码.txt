跟上一题代码一样，一点都没改。
dp[i][j] 表示前 i 个房子，选第 j 个颜色需要的费用，实际上不用重新申请空间，直接在costs进行操作就行。
dp[i][j] = dp[i-1][j] + min(dp[i-1][除去第j个颜色])

```
class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        if len(costs) == 0:
            return 0
        if len(costs) == 1:
            return min(costs[0])
        lenght = len(costs)
        k = len(costs[0])
        
        for i in range(1, lenght):
            for j in range(k):
                tmp = costs[i-1][:]
                tmp.pop(j)
                costs[i][j] = costs[i][j] + min(tmp)
        return min(costs[-1])
```

