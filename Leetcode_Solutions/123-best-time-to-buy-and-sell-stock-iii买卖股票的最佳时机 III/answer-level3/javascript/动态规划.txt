```javascript
var maxProfit = function(prices) {
    if(prices.length < 2) return 0

	let dp = [],sum = 0

	for(let i = 0 ; i < prices.length ; i ++) {
		dp[i] = []
		for(let j = 0 ; j <= 2 ; j++) {
			dp[i][j] = [Number.NEGATIVE_INFINITY, Number.NEGATIVE_INFINITY] 
		}
	}

	dp[0][0] = [0, -prices[0]]

	for(let i = 1 ; i < prices.length ; i++) {
		//如果当前是一次都没买的状态，则收益等于前一天的收益，前一天的收益也是一次都没买的状态，当前状态收益恒为0
		dp[i][0][0] = dp[i-1][0][0]
		//如果当前是买了一次的状态，则前一天可能已经买了，或者就是今天买的，则当前状态的最大收益是两者的最小代价
		dp[i][0][1] = Math.max(dp[i-1][0][1], dp[i-1][0][0] - prices[i])
		//如果当前是卖了一次且没买第二次的状态，则前一天可能已经卖了，或者就是今天卖的，则当前状态的最大收益是两者中的较大者
		dp[i][1][0] = Math.max(dp[i-1][1][0], dp[i-1][0][1] + prices[i])
		//如果当前是卖了一次且买了第二次的状态，则前一天可能已经买了，或者就是今天买的，则当前状态的最大收益是两者的最小代价
		dp[i][1][1] = Math.max(dp[i-1][1][1], dp[i-1][1][0] - prices[i])
		//如果当前卖了第二次，则前一天可能已经卖了，或者就是今天卖的，则当前状态的最大收益就是两者中的较大者
		dp[i][2][0] = Math.max(dp[i-1][2][0], dp[i-1][1][1] + prices[i])

		sum = Math.max(dp[i][0][0], dp[i][1][0], dp[i][2][0])
	}
	return sum
};
```