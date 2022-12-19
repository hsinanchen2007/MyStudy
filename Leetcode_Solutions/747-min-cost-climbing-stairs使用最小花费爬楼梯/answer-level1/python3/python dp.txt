### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0, 0] + cost
        dp.append(0)
        
        """
        过程是经过当前节点的耗费，由前面两个阶梯决定， 最终要到达终点
        
        0，0，c1, c2, ....   cn, 0
        
        c1 = min(dp[c1 - 1], dp[c1 - 2]) + c1
        
        
        """
        
        for i in range(2, len(dp)):
            dp[i] = min(dp[i - 1], dp[i - 2]) + dp[i]
        
        return dp[-1]
        
```