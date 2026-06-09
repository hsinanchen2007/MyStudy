


# 贪心算法
## leetcode中的贪心算法-简单类
    

#### **1.买卖股票的最佳时机2**

        给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
        注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
       
#####  **示例**       
```
输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
```
 
```
class Solution:
    # def maxProfit(self, prices: List[int]) -> int:
        # return sum(b - a for a, b in zip(prices, prices[1:]) if b > a)
    def maxProfit(self,prices):
        maxsum=0
        for i in range(1,len(prices)):
            if prices[i]-prices[i-1]>0:
                maxsum += prices[i]-prices[i-1]
        return maxsum
```

*   解释zip函数这一行的意思
`sum(b - a for a, b in zip(prices, prices[1:]) if b > a)`

![image.png](https://pic.leetcode-cn.com/d31ac8383d39da044e917aa1106f901b6155e7a6d5cc3472ad62d29224b6a4a9-image.png)


其实就是把相邻两数做比较，如果b>a就相加，得到最后的值，一道最基础的贪心算法题。





