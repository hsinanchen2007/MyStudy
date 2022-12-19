### 解题思路
膜拜动态规划大佬

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #方法一：一次遍历
        max_price = 0
        min_pirce = float('inf')
        
        for i in prices:
            min_pirce = min(min_pirce, i)
            max_price = max(max_price, i-min_pirce)
        
        return max_price

        #学习大佬的动态规划
        dp_i_0 = 0
        dp_i_1 = float('-inf')
        for price in prices:
            dp_i_0 = max(dp_i_0, dp_i_1 + price)
            dp_i_1 = max(dp_i_1, -price)
        
        return dp_i_0
            

```