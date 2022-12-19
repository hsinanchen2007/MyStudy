### 解题思路
从函数图形角度理解买卖股票的最佳时点
必要条件是极值小（大）值点，即小（大）于等于前后两值
从必要条件出发，缩小运算范围。
找到极大值（卖点）则与当前找到的极小值（买点）做差
找到更小的极小值便清空历史的买卖点

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        length=len(prices)
        if(length<2):
            return 0
        output=0
        buy,sell=prices[0],0
        for i in range(1,length):
            if prices[i]<buy and i!=length-1 and prices[i]<=prices[i-1] and prices[i]<=prices[i+1]:
                buy=prices[i]
                sell=0
            if prices[i]>=prices[i-1] and (i==length-1 or prices[i]>=prices[i+1]) and prices[i]>=sell:
                sell=prices[i]
                if(output<sell-buy):
                    output=sell-buy
        return output
```