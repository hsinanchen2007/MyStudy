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
        if len(prices)<2:
            return 0
        n=prices[0]
        m=[0 for i in range(len(prices))]
        for i in range(1,len(prices)):
            if prices[i]<n:
                n=prices[i]
            m[i]=max((prices[i]-n),m[i-1])
        return max(m)


```