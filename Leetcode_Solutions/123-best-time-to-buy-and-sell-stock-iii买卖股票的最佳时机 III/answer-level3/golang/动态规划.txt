### 解题思路
#### 动态规划求解的问题的一般要具有 3 个性质
1. 最优化：如果问题的最优解所包含的子问题的解也是最优的，就称该问题具有最优子结构，即满足最优化原理。子问题的局部最优将导致整个问题的全局最优。换句话说，就是问题的一个最优解中一定包含子问题的一个最优解。
2. 无后效性：即某阶段状态一旦确定，就不受这个状态以后决策的影响。也就是说，某状态以后的过程不会影响以前的状态，只与当前状态有关，与其他阶段的状态无关，特别是与未发生的阶段的状态无关。
3. 重叠子问题：即子问题之间是不独立的，一个子问题在下一阶段决策中可能被多次使用到。（该性质并不是动态规划适用的必要条件，但是如果没有这条性质，动态规划算法同其他算法相比就不具备优势）

#### 状态
第一次买入（fstBuy） 、 第一次卖出（fstSell）、第二次买入（secBuy） 和 第二次卖出（secSell） 这四种状态。

#### 转移方程
这里可以有两次的买入和卖出，也就是说 买入 状态之前可拥有 卖出 状态，所以买入和卖出的转移方程需要变化。

fstBuy = max(fstBuy ，  -price[i])

fstSell = max(fstSell，fstBuy + prices[i] )

secBuy = max(secBuy ，fstSell -price[i]) (受第一次卖出状态的影响)

secSell = max(secSell ，secBuy + prices[i] )

#### 边界
一开始 fstBuy = -prices[0]

买入后直接卖出，fstSell = 0

买入后再卖出再买入，secBuy - prices[0]

买入后再卖出再买入再卖出，secSell = 0

最后返回 secSell 。
### 代码

```golang
func maxProfit(prices []int) int {
    firstBuy,firstSell := int(math.MinInt32),0
    secondBuy,secondSell := int(math.MinInt32),0
    for _, price := range prices{
        firstBuy = max(firstBuy,-price)
        firstSell = max(firstSell,firstBuy+price)
        secondBuy = max(secondBuy,firstSell-price)
        secondSell = max(secondSell,secondBuy+price)
    }
    return secondSell

}
func max( a,b int)int{
    if a > b{
        return a
    }
    return b
}
```