### 解题思路
按照labuladong大神写的动态规划的解法（“一个方法团灭6道股票问题”）写的Python版本
击败100%
labuladong的动态规划讲得太好了

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<2: return 0
        dp_i_0, dp_i_1 = 0, -prices[0]
        for i in range(1,len(prices)):
            dp_i_0 = max(dp_i_0,dp_i_1+prices[i])
            dp_i_1 = max(dp_i_1,-prices[i])
        return dp_i_0
```