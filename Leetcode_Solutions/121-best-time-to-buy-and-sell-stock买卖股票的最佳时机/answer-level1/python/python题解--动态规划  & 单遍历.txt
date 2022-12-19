### 解题思路
摸排动态规划大佬
[https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/]()

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #方法一：一次遍历，每次取前面的最小值和后面的最大值
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