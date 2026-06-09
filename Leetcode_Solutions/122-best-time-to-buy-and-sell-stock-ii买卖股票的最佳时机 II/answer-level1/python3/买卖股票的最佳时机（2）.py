### 解题思路
以`prices = [7,1,5,3,6,4]`为例，说明一下解题思路

观察这个列表，可以发现在第2天（股票价格 = 1）的时候买入，第3天（股票价格 = 5）卖出，获利为4。然后，在第4天（股票价格 = 3）的时候买入，第5天（股票价格 = 6）卖出，获利为3。总利润为7。

所以，只要满足后一天比前一天的值大即可，累加起来即可得到总利润。

**注意：** 题目要求在再次购买前要出售掉之前的股票，并没有说同一天不能完成**卖出**和**买入**这两个动作。

所以，可以理解为在当天卖出股票之后，又以卖出价格买入了股票。在计算当前利润时，如果为`卖出价格 - 买入价格`为负值，则当前利润`curr_profit = 0`。这样，在遍历时遇到后一天小于前一天的值，也不会影响最后的结果。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:return 0
        buy_price , sell_prcie = prices[0] , 0
        curr_profit , total_profit = 0, 0
        for i in range(1,len(prices)):
            sell_prcie = prices[i] #卖出价格

            curr_profit = 0 if sell_prcie - buy_price < 0 else sell_prcie - buy_price
           
            total_profit += curr_profit

            buy_price = prices[i]
        return total_profit
```

![公众号二维码.jpg](https://pic.leetcode-cn.com/66d19077b9151d52b466764deda7e464bc7ef7b0ae7c50fbee8296e3fe7e3ccf-%E5%85%AC%E4%BC%97%E5%8F%B7%E4%BA%8C%E7%BB%B4%E7%A0%81.jpg)
这是我的公众号，在上面会分享我刷leetcode的过程，走过路过的点个关注吧，拜托了！
