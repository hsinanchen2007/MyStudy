### 解题思路
利用滑动窗口的思路，每次更新最大值时，存储差价，每次遇到最小值时，初始化最大值

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices)==0: return 0
        high,low,flag = -1,-1,0
        l = []
        for i in prices:
            if i>high:
                high =i
                if flag == 1:
                    l.append(high-low)
                else:
                    low = high
                flag = 1
            if i<low:
                low = i
                high = low
        if len(l)==0: l.append(0)
        return max(l)
            

```