### 解题思路
固定卖出节点时 ，买入价越低，利润越高，所以，
一个变量储存之前的最小价格，每访问一个节点就对其进行更新
一个变量储存当前节点卖出的最大利润 并与之前的最大利润比较，进行更新
因为此方法限制了必须有交易，故在最后添加一步，若交易的最大利润为负，则选择不交易
只需访问一遍列表
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices) < 2:
            return 0
        min = prices[0]#记录之前的最小值
        max=prices[1] - min #记录以当前节点为卖出价时，所获的最大利润
        i=2
        while i< len(prices):
            if prices[i-1] < min:
                min = prices[i-1]
            cur_r = prices[i]-min
            if cur_r >max:
                max = cur_r
            i +=1
        if max>0:
            return max
        else:
            return 0
```