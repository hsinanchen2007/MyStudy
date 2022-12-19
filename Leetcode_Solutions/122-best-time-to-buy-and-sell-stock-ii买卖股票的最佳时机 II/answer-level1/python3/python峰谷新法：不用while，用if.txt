```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        '''
        题意：prices是股票各天价格的集合，index+1为当天，买卖不限次数，但同时拥有一支股票，即买了之后卖了才能再买，求最大收益。
        问题关键：相比121，该题改动了买卖次数的条件，需要从该方面入手
        思路：
        1.我们先分析股票价格排列的情况
        ①如果股票价格一直跌，则咱们需要选价格最小的时候买入，价格回升时卖出方能使利益最大化；
        ②而买入后价格一直涨，我们只需要选择价格最高的时候卖出即可，这时利益最大化，中间卖出都会再买入都会浪费掉部分价格差；
        ③若价格涨后又落，则进行①
        2.在末尾的时候，②中没有价格下降而卖出的判断，所以需要加上i == len(prices)-1 and prices[i]>=prices[i-1]的判断
        3.缺少prices为[]的判断
        反思与改进：
        1.如上，进行情况分析是较为系统的算法题解决方法
        2.仍需要看一些算法思想的书籍，系统学习，掌握系统方法
        '''
        if not prices:
            return 0
        from sys import maxsize
        profit = 0
        min_p = prices[0]
        max_p = prices[0]
        for i in range(1,len(prices)):
            if prices[i-1] > prices[i]:
                profit += max_p - min_p
                min_p = prices[i]
                max_p = prices[i]
            if prices[i] < min_p:
                min_p = prices[i]
            elif prices[i] > max_p:
                max_p = prices[i]
            if i == len(prices)-1 and prices[i]>=prices[i-1]:
                profit += max_p - min_p
        return profit
```
