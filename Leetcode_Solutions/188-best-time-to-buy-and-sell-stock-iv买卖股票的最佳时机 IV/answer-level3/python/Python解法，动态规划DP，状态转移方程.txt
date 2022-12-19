
*因为至少2天，完成一次交易
所以当交易次数 > 总天数/2天时，无交易次数限制*

# 无交易次数限制时：

**状态转换方程：**
(今天的)空仓 0 = 最大值 (昨天的)空仓 0 /满仓 1 - price
(今天的)满仓 1 = 最大值 (昨天的)满仓1 /平仓 0 + price
**合起来写就是：**
最佳的: [(今天的)空仓 0，(今天的)满仓 1] = [最大值: (昨天的)空仓 0 /满仓 1 - price, 最大值: (昨天的)满仓1 /平仓 0 + price]
```
for price in prices:
state = [0, -price]: 这是第一天状态 [空仓，满仓]
state = [ max(state[0], state[1] - price), max(state[1], state[0] + price)] 这是之后几天的状态推演，直到最后一天。
return state[0] 果然股票卖出去的时候钱才是最多的科科
```

当交易次数 < 次数限制的时候
```
for price in prices: 
for k in range(k+1): 
```
那么多了一个参数: 股票交易次数限制 - k
```
state[k次的时候] = [ max(state[0], state[k - 1][1] - price), max(state[1], state[0] + price)] 
```
第一次购买用了一次机会，第二次购买即为第一次机会+一次机会，直到用尽n次机会
```
return state[-1][0]
```

最终代码
```
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices:return 0
        if k > int(len(prices)/2): 
            state = [0, -prices[0]]
            for price in prices: 
                state = [max(state[0], state[1]+price), max(state[1], state[0]-price)]
            return state[0]
        else: 
            state = [[0, -prices[0]] for i in range(k+1)]
            for price in prices: 
                for k in range(1, k+1):
                    state[k] = [max(state[k][0], state[k][1]+price), max(state[k][1], state[k-1][0]-price)]
            return state[-1][0]
```

