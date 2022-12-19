### 解题思路
一开始想的是暴力法，但是Python会超时。
看了官方解答，发现最一开始的时候自己想的也有点眉目，但是错在想直接找到最大和最小，然后求得最大收益。关键在于，需要在动态遍历中找到当前序列中的最小值，并求出相应的最大差值。在遍历完成后，就可以得到全序列的最大差值。

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # l = len(prices)
        # profit = 0
        # for i in range(l):
        #     for j in range(i+1,l):
        #         if prices[j] > prices[i]:
        #             get = prices[j] - prices[i]
        #             if get > profit:
        #                 profit = get
        # return profit
        inf = int(1e9)
        minprice = inf
        maxprofit = 0
        for price in prices:
            minprice = min(minprice,price)
            maxprofit = max(maxprofit,price-minprice)
        return maxprofit
```