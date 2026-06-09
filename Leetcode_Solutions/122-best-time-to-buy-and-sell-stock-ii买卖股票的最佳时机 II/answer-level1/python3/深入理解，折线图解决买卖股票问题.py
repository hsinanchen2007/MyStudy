思路：先买入一次，再卖出，如此n次循环，得到最大的差值。

转化为一个折线图：每次找出最低的波谷（为什么说最低呢，因为可能连续几次都是梯度下降，这样最后一个点才能作为这次的波谷）。同理找出与这个波谷最近的波峰。得到尽可能多的波谷和波峰，就能得到结果。

题目的特征和注意的要点：
1.找到梯度下降的最低点和随其后的梯度增加的最高点
需要比较两个相邻的点的大小，并设置索引递增条件
2.设置两个变量peak和valley，存储每次两个峰值
官方题解2会有索引超出错误，去掉peak和valley的初始赋值即可



```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        profit = 0
        while(i < len(prices)-1):
            while(i < len(prices)-1 and prices[i] >= prices[i+1]):
                i += 1
            valley = prices[i]
            
                
            while(i < len(prices)-1 and prices[i] <= prices[i+1]):
                i += 1
            peak = prices[i]
                
            profit += peak - valley
        return profit
```

