### 解题思路
1、dp[i] 标识 i 的接口

### 代码

```golang
package main

//零钱兑换

//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1
//  dp[i] = min(dp[i-1],dp[i-2],dp[i-5],dp[i-7]) +1
func coinChange(coins []int, amount int) int {
	var dp = make([]int, amount+1)
	for i := 0; i <= amount; i++ {
		dp[i] = -1
	}
	dp[0] = 0
	for i := 1; i <= amount; i++ {
		for j := 0; j < len(coins); j++ {
			if i-coins[j] >= 0 && dp[i-coins[j]] != -1 {
				if dp[i] == -1 || dp[i] > dp[i-coins[j]]+1 {
					dp[i] = dp[i-coins[j]] + 1
				}
			}
		}
	}
	return dp[amount]
}

```