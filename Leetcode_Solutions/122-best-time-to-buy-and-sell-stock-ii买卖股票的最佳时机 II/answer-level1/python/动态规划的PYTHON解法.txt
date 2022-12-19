### 解题思路
相对于之前那个题来说感觉这道题更加简单一些
其实就是把所有的上升峰标记出来
之后进行相加
用了动态规划的只是
![屏幕快照 2020-03-02 下午7.02.26.png](https://pic.leetcode-cn.com/d0396fa8f95ff79fcc0c9d884de317ae59fd73faea93fe747be872c8ba1464ac-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-02%20%E4%B8%8B%E5%8D%887.02.26.png)

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices == []:
            return(0)
        else:
            start = prices[0]
            profit = 0
            for i in prices[1:]:
                x = i - start
                start = i
                if x >= 0:
                    profit = profit + x
                else:
                    continue    
        return(profit)
```