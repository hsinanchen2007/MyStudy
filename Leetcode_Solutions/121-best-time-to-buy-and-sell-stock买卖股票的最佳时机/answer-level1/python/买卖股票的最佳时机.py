### 解题思路 1.0
方法：双循环
步骤：
1. 遍历股票信息，以当前遍历元素为买入价
2. 遍历该元素以后的列表找到获取最大利润的卖出价，找到最大利润
3. 返回最大利润
### 执行结果
超出时间限制
### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        temp = 0

        for i, buy in enumerate(prices):

            for sell in prices[i+1:]:
                temp = sell - buy

                if temp > profit:
                    profit = temp

        return profit

```

### 解题思路 2.0
**参考信息：
作者：z1m
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/gu-piao-wen-ti-python3-c-by-z1m/**
优化：使用列表函数，仅遍历一次列表，降低时间复杂度
方法：假设在最低点买入，找到获取最大利润的高点卖出
步骤：
1. 判断股票信息是否为空，若为空，则无法进行交易，直接返回0
2. 遍历股票信息，同步筛选最大利润和最低买入价格
3. 返回最大利润
### 执行结果
执行用时：20 ms
内存消耗：13.2 MB
### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices != []:

            profit = 0
            price_min = prices[0]
        
            for price in prices:

                profit = max(profit, price - price_min)
                price_min = min(price_min, price)

            return profit
        else:
            return 0

```