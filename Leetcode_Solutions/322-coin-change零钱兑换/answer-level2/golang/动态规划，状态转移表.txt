##### 可以画出状态转移表，辅助思考一下，得出状态转移方程，然后翻译成代码。如图，状态转移表，表中数据代表最少的硬币个数，具体可以看算法图解第九章
![image.png](https://pic.leetcode-cn.com/da8ca088bb51a0fa6fb910c3211ac0853d42ce8f1e203c4b7827b58d4498ceb8-image.png)
<br>
```
func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = amount+1
	}
	dp[0] = 0
	for i := 1; i <= amount; i++ {
		for _, coin := range coins {
			if coin <= i {
				dp[i] = int(math.Min(float64(dp[i]), float64(dp[i-coin]+1)))
			}
		}
		fmt.Println(dp)
	}
	if dp[amount] > amount {
		return -1
	} else {
		return dp[amount]
	}
}
```