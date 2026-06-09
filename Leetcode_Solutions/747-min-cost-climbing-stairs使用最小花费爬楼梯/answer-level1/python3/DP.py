
### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost)<3:return min(cost)
        # if from dp_i to top
        dp_0,dp_1 = cost[0],cost[1]
        for i in range(2,len(cost)):
            # slide array
            dp_0,dp_1 = dp_1,min(dp_0+cost[i],dp_1+cost[i])
        return min(dp_0,dp_1)
```