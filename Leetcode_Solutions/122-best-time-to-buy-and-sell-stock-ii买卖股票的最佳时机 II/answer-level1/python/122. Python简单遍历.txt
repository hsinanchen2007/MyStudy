### 解题思路
如果把所有的价格画成一个折线图，那么实际上我们需要把所有递增的部分的价格差加在一起，那么更简单的，如果连续两天中第二天的价格大于第一天我们就把两天的差加在最终答案上。


### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices)
        if length == 0:
            return 0
        res = 0
        for i in range(1, length):
            if prices[i] > prices[i - 1]:
                res += prices[i] - prices[i - 1]
        return res
```