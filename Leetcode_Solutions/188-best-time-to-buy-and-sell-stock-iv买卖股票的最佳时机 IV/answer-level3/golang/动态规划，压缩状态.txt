首先不压缩状态，会 OOM，这是错误的版本，但是容易理解：

```
import "math"

func maxProfit(k int, prices []int) int {
	var (
		i, b, j                                          int
		todaySell, todayBuy, yesterdayNot, yesterdayHave int
		length                                           = len(prices)
		// dp[i][b][j]: 在第 i 天第 j 次是否（b）持有股票情况下的资产
		dp = make([][][]int, length)
	)
	if length == 0 || k == 0 {
		return 0
	}
	for i = 0; i < length; i++ {
		dp[i] = make([][]int, 2)
		dp[i][0] = make([]int, k)
		dp[i][1] = make([]int, k)
	}
	for i = 0; i < k; i++ {
		dp[0][1][i] = math.MinInt32
	}
	dp[0][1][0] = -prices[0]

	for i = 1; i < length; i++ {
		for j = 0; j < k; j++ {
			todaySell = dp[i-1][1][j] + prices[i]
			yesterdayNot = dp[i-1][0][j]
			dp[i][0][j] = max(todaySell, yesterdayNot)

			if j == 0 {
				yesterdayNot = 0
			} else {
				yesterdayNot = dp[i-1][0][j-1]
			}
			todayBuy = yesterdayNot - prices[i]
			yesterdayHave = dp[i-1][1][j]
			dp[i][1][j] = max(todayBuy, yesterdayHave)
		}
	}

	b = 0
	for i = 0; i < k; i++ {
		if dp[length-1][0][i] > b {
			b = dp[length-1][0][i]
		}
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```

接着就是状态压缩版本：

```
import "math"

func maxProfit(k int, prices []int) int {
	var (
		i, b, j, maxTrade                          int
		yesterdayNot, yesterdayNot2, yesterdayHave int
		length                                     = len(prices)
		// dp[i][b]: 在第 i 次是否（b）持有股票情况下的资产
		dp [][]int
	)
	maxTrade = min(length/2, k)
	if length == 0 || k == 0 || maxTrade == 0 {
		return 0
	}
	dp = make([][]int, maxTrade)
	for i = 0; i < maxTrade; i++ {
		dp[i] = make([]int, 2)
	}
	dp[0][1] = -prices[0]
	for i = 1; i < maxTrade; i++ {
		dp[i][1] = math.MinInt32
	}

	for i = 0; i < length; i++ {
		for j = 0; j < maxTrade; j++ {
			yesterdayNot = dp[j][0]
			if j == 0 {
				yesterdayNot2 = 0
			} else {
				yesterdayNot2 = dp[j-1][0]
			}
			yesterdayHave = dp[j][1]

			dp[j][0] = max( // 今天没有
				yesterdayHave+prices[i], // 昨天有，今天买了，同一次交易周期
				yesterdayNot,            // 昨天也没有
			)
			dp[j][1] = max( // 今天有
				yesterdayNot2-prices[i], // 昨天没有，今天买了，不同周期
				yesterdayHave,           // 昨天有
			)
		}
	}

	b = 0
	for i = 0; i < maxTrade; i++ {
		if dp[i][0] > b {
			b = dp[i][0]
		}
	}
	return b
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```
