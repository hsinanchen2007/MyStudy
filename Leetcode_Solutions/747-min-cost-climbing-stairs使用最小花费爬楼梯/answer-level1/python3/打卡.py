### 解题思路
这题坑在，cost[-1]不是目的地，再后一个才是。所以设计dp数组的时候要比cost的长度多一位，dp[-1] = min(dp[-2],dp[-3])
举个例子，[10,15,20]，走两步到15，再走两步到目的地。


### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = (len(cost) + 1)
        dp = [0] * n
        dp[0] = cost[0]
        dp[1] = min(cost[1] , dp[0] + cost[1])
        for i in range(2,n-1):
            dp[i] = min(dp[i-2]+cost[i],dp[i-1]+cost[i])
        dp[-1] = min(dp[-2],dp[-3])
        return dp[-1]        
```