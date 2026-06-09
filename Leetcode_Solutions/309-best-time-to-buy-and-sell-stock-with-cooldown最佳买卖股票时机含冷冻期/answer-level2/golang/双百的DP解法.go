### 解题思路
和之前的买卖股票题目相比，此题多了一个冷冻期。  
以前的状态只要定义两个即可：买入，卖出。  
而现在就需要多定义一个冷冻期，所以DP数组可以声明为[3]int(或者用3个变量).  
不持有的状态方程依然不变还是 max(保持“不持有”状态，前一天买入+当前股价)
而持有的状态方程就不能继承”买入“和”保持持有“了， 应该是 max(保持持有，前一天冷冻期-当前股价)  
冷冻期则简单，只要继承前一天“不持有”的值就行了。

### 代码

```golang
func maxProfit(prices []int) int {
	n := len(prices)
	if n == 0 || n == 1 {
		return 0
	}
	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}
	dp := [3]int{0, -prices[0], 0} // 这里三个值分别是不持有，持有，冷冻期
	for i := 1; i < len(prices); i++ {
		tmp := dp[0] // 避免不持有值被覆盖，用临时变量暂存，之后赋给“冷冻期”

		dp[0] = max(dp[0], dp[1]+prices[i]) // 卖出和别的题一样
		dp[1] = max(dp[1], dp[2]-prices[i]) // 如果要买入，需要继承“保持持有”和“冷冻期”二者最大值
		dp[2] = tmp
	}
	return dp[0]
}
```