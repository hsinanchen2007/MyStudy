### 解题思路
# 注意：这个题目的最终点不是最后一个台阶，而是楼顶，因此最终的结果是判断倒数第一个台阶与倒数第二个台阶到楼顶谁近！！！


### 代码

```python
class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        # 优化空间复杂度O(1)
        cur,pre = 0,0
        for i in range(len(cost)):
            cur,pre = min(pre,cur)+cost[i],cur
        return min(cur,pre)
        
        
        # dp[i] = min(dp[i-2],dp[i-1])+num
        dp = [0,0]
        for i in range(2,len(cost)+2):
            dp.append(min(dp[i-2],dp[i-1])+cost[i-2])
        return min(dp[-1],dp[-2])
        
```