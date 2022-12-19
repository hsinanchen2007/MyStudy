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
        n=len(prices)
        huoli = 0
        for i in range(1,n) :
            a=prices[i] - prices[i-1]            
            if a>=0:
                huoli = a+huoli 
        return huoli


```