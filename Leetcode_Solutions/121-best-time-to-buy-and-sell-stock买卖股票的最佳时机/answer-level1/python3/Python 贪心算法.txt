### 解题思路
股票问题
贪心算法，一次遍历
还可以用动态规划/状态机

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if(not prices):
            return 0
        maxprice = 0
        minprice = prices[0]
        for price in prices:
            minprice = min(minprice,price)
            maxprice = max(maxprice,price-minprice)
        return maxprice
            

```