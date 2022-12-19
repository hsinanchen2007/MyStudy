![image.png](https://pic.leetcode-cn.com/22dc0a699a9922e856f65e9fed294582cd21da97e680ebb1c8b2f11d73b31397-image.png)


把所有卖点全部累加，多卖的再减掉

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices == []:
            return 0
        lowlv = prices[0]
        profit = 0
        i = 1
        while i < len(prices):   
            if prices[i] <= prices[i-1]:
                lowlv = prices[i]# 低买
            else:
                profit -= prices[i-1] - lowlv# 减去上次较低的卖点
            profit += prices[i] - lowlv# 高卖
            i += 1
        return profit
```
不会别的算法
