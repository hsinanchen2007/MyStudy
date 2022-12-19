### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        sin  = 0 
        value = []
        a=len(prices)
        for i in range(1,a):
            value.append ( max(prices[i:])-prices[i-1])
        if value != []:
            sin=max(value)
        if sin >0:
            return sin
        else:
            return 0


```