### 解题思路
https://blog.csdn.net/NLSQQ/article/details/104919528
买卖股票的最佳时机系列解法

### 代码

```golang
func Max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
 
func maxProfit(prices []int) int {
	pLen := len(prices)
    k := 2
	if pLen < 1 {
		return 0
	}
    //买卖股票的最佳时机II
    if pLen/2 < k {
		ans := 0
		for i:=0; i<len(prices)-1; i++ {
			if prices[i] < prices[i+1] {
				ans = ans + prices[i+1] - prices[i]
			}
		}
		return ans
	}
    //买卖股票的最佳时机III
	dp := make([][2][3]int, pLen+10)
	for i := 0; i <= k; i++ {
		dp[0][1][i] = -prices[0] //初始化
	}
	for i:=1; i<pLen; i++ {
		dp[i][1][0] = Max(dp[i-1][1][0], -prices[i]) 
		for kp:=1; kp<=k; kp++ {
			dp[i][0][kp] = Max(dp[i-1][1][kp-1]+prices[i], dp[i-1][0][kp]) //卖出
			dp[i][1][kp] = Max(dp[i-1][0][kp] - prices[i], dp[i-1][1][kp]) //买入
		}
	}
	return dp[pLen-1][0][k]
}
```