### 解题思路
// DP
注意：卖出才算一次交易完成
状态的定义：dp[i]，表示到第i天的最大利润
dp[i][j]，表示第i天持有股票与否的最大利润，j取值[0, 1]
dp[i][j][k]，表示第i天是否持有股票并且交易了k次的最大利润
dp[i][k][0] 表示不持有股票交易k次的最大利润， dp[i][k][1] 表示持有一只股票交易了k次的最大利润
有多少个维度，一般就需要几个循环
遍历天数以及交易次数
dp[i][k][0] = max{dp[i-1][k][0], dp[i-1][k-1][1] + price[i]}  不动或者卖出
dp[i][k][1] = max{dp[i-1][k][0]-price[i], dp[i-1][k][1]}  不动或者买入

因为天数这一维度，只需要前一天的数据，因此只保留昨天和今天的最大利润。下面的代码做了状态压缩

```
执行用时 :4 ms, 在所有 golang 提交中击败了88.66%的用户
内存消耗 :2.7 MB, 在所有 golang 提交中击败了75.00%的用户
```

### 代码

```golang
func maxProfit2(k int, prices []int) int {
	if len(prices) == 0 || k < 1 {
		return 0
	}
	res := 0
	// 满足一天交易，第二天就卖出。特殊处理，防止k太大，导致分配超大数组，引起OOM
	if k >= len(prices) / 2 {
		for i := 1; i < len(prices); i++ {
			if prices[i]-prices[i-1] > 0 {
				res += prices[i] - prices[i-1]
			}
		}
		return res
	}
	// DP
	// 初始化数据结构
	// 只需要相邻两天的状态
	dpLast := make([][2]int, k+1) // 前一天状态[0...k]
	dp := make([][2]int, k+1)     // 当前天状态
	// 初始化
	dpLast[0][1] = -prices[0]
	for i := 1; i <= k; i++ {
		dpLast[i][1] = max(dpLast[i-1][1], -prices[0]) // 持有之前的，或者持有今天的，看谁利润大
	}
	// 递推
	for i := 1; i < len(prices); i++ {
		dp[0][1] = max(dpLast[0][1], -prices[i])
		for j := 1; j <= k; j++ { // 注意k的取值，最多可交易k次
			dp[j][0] = max(dpLast[j][0], dpLast[j-1][1]+prices[i]) // 不动或卖出
			dp[j][1] = max(dpLast[j][0]-prices[i], dpLast[j][1])   // 买入(不算交易)，或不动
		}
		// 保存状态
		copy(dpLast, dp)
	}
	return dp[k][0]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}


```