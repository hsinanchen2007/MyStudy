### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        d_i_0 = 0
        d_i_1 = float('-inf')

        for price in prices:
            temp = d_i_0
            d_i_0 = max(d_i_0, d_i_1 + price)
            d_i_1 = max(d_i_1, temp - price)
        
        return d_i_0
```