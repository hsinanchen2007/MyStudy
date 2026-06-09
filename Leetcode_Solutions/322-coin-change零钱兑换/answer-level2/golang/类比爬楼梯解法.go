### 解题思路
把这个题理解成爬楼梯问题，台阶是11， 一次能走的步数为各种面额， 然后求到达指定台阶最少步数。

假设每一个台阶都需要 amount+1 步， 然后比较各个面额（一次能走步数）到达该台阶最少次数。
### 代码

```golang
func coinChange(coins []int, amount int) int {
	n := len(coins)
	if n == 0  {
		return -1
	}

	dp := make([]int, amount+1)
	for i:=0; i<=amount; i++ {
		if i == 0 {
			dp[i] = 0
			continue
		}
		dp[i] = amount + 1
	}

	for i:=1; i<=amount; i++ {
		for j:=0; j<n; j++ {
			if coins[j] <= i {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1)
			}
		}
	}

	if dp[amount] > amount {
		return -1
	} else {
		return dp[amount]
	}
}

func min(x, y int) int {
	if x <= y {
		return x
	}

	return y
}
```