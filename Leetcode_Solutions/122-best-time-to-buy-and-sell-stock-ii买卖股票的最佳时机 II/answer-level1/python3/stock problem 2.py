### 峰谷法

- 啊我第一思路和官方题解一模一样：寻找邻近的波谷（买入点）和波峰（卖出点），计算两者差值。所有的差值累积成总利润。

- 因此，设立了两个变量`prev_diff`和`next_diff`，分别表示前向差值和后向差值，用于判断是不是波谷和波峰。每遇到波谷，记录该点的价格`buy_in`；每遇到波峰，就在总利润`profit`上累积`prices[i]-buy_in`。

- 注意第0天和最后一天的处理。

```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        buy_in = -1 # 买入股票的价格
        profit = 0
        for i in range(len(prices)):
            prev_diff = prices[i]-prices[i-1] if i!=0 else 0 
            next_diff = prices[i+1]-prices[i] if i!= len(prices)-1 else 0
            # 买入点
            if prev_diff <= 0 and next_diff >= 0 :
                buy_in = prices[i]
            # 卖出点
            elif prev_diff >= 0 and next_diff <= 0 and buy_in != -1:
                profit += prices[i] - buy_in
                buy_in = -1
        return profit
```

复杂度分析：
- 时间复杂度：O(N)
- 空间复杂度：O(1)

### 等效法 

- 假设`prices`为[1,2,3,4,5,2]。依我们第一种解法，我们的思路是找出1是波谷，5是波峰，所以利润为`5-1=4`。虽然最后一个2也是波谷，但由于它后面没有波峰了，所以无法卖出。

- 事实上，我们不需要傻傻地去算哪天买入，哪天卖出。只要价格一直上升，我们就把价格差算到总利润里。即`(2-1)+(3-2)+(4-3)+(5-4)=4`。

- 或者，你可以理解为题目允许“同一天卖出&买入“。虽然与原题的股票交易过程不同，但是计算出的利润是等效的。

```python []
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <= 1:
            return 0
        profit = 0
        for i in range(1, len(prices)):
            profit += max(0, prices[i]-prices[i-1])
        return profit
```

复杂度分析：
- 时间复杂度：O(N)
- 空间复杂度：O(1)