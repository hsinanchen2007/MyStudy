执行用时16 ms击败了99.74%,内存消耗击败了100.00%。思路：一次遍历。把数据想象成柱状图。当前遍历值有3种状态中的一种，1.局部的谷底；2.局部爬坡；3.其他值。
所以当遇到新的值时，先判断是否是新谷底，是就更新；然后判断是否是在爬坡，判断当前爬坡值是否是最大高度。
```python
class Solution(object):
    def maxProfit(self, prices):
        minl=0     #记录从左边起，谷底处的指针位置
        l=len(prices)  
        mx=0       #记录当前最大返回值
        for i in range(l)
            if prices[i]<prices[minl]:
                minl=i
            elif prices[i]-prices[minl]>mx:
                mx=prices[i]-prices[minl]
        return mx
```