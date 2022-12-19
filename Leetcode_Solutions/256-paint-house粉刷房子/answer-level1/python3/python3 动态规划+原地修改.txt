### 解题思路
实际上就是在cost原地累加
如果当前选择图第一种颜色，那么就选择前面涂另外两种颜色中花费最小的那个
转移方程dp[i][x]+=min(dp[i][x-1]+dp[x+1])

### 代码

```
class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0
        dp=costs
        for i in range(1,len(costs)):
            dp[i][0]+=min(dp[i-1][1],dp[i-1][2])
            dp[i][1]+=min(dp[i-1][0],dp[i-1][2])
            dp[i][2]+=min(dp[i-1][0],dp[i-1][1])
        return min(dp[-1])
        

       
```