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
        if len(prices)==0 or len(prices)==1:
            return 0
        min=prices[0]

        ans=0

        for price in prices:
            if price-min>ans:
                ans=price-min

            if price<min:
                min=price

        return ans
```