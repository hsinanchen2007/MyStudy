### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        if len(prices)==0 or len(prices)==1:
            return 0
        pre=prices[0]
        ans=0
        for price in prices:
            if price>pre:
                ans=ans+price-pre
                pre=price
            else:
                pre=price
        return ans
```