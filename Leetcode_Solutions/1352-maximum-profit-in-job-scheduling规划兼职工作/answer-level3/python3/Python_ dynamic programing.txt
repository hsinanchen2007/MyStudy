### 解题思路
此题本质上和打家劫舍类似。可以用一个数组记录在每一个结束时间处可以得到的最大利润。因为要比较结束的时间，所以把结束时间一并记录。

这个最大利润可以从两个途径获得：
* 包含当前任务，那么最大利润就是当前利润，加上结束时间在当前任务开始时间之前的最大利润
* 不包含当前任务，那么最大利润就是前一个最大利润


### 代码

```python
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(profit)
        idx = sorted(list(range(n)), key = lambda x: endTime[x])
        dp = [[0, 0] for _ in range(n+1)]        
        for i in range(n):
            for j in range(i, -1, -1):
                if dp[j][1] <= startTime[idx[i]]:
                    cur = dp[j][0] + profit[idx[i]]
                    break
            dp[i+1] = dp[i] if dp[i][0] >= cur else [cur, endTime[idx[i]]]            
        return dp[-1][0]
```