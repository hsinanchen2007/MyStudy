### 解题思路
现在看prices的数组，就相当于**上帝模式**，看在哪一天买哪一天卖赚的最多
所以我们在卖的时候就已经*假定之前已经买入了*
评论区看到的解释：
- 从第一天到最后一天，不错过每一次隔天的上涨
- 每次买完股票，第二天就出售掉
- 只要明天股票价格比今天高，今天就买入
- 买入和出售可以发生在同一天

### 代码

```golang
func maxProfit(prices []int) int {
	// 极端情况先排除
	if len(prices) < 2 {
		return 0
	}
	// 当前收益
	profit := 0
	// 从第二天开始，假设立刻就买入了
	for i := 1; i < len(prices); i++ {
		// 当天价格高于前一天，就卖掉
		if prices[i] > prices[i-1] {
			// 更新收益
			profit += prices[i] - prices[i-1]
		}
	}
	// 返回最终收益
	return profit
}
```