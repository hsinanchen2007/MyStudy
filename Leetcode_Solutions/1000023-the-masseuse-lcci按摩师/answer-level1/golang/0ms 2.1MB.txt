### 解题思路

dp 参见代码 跟股票的类似

### 代码

```golang

/*
	dp[i][0] = max(dp[i-1][0], dp[i-1][1]) 	//第i个不预约，那么第i-1个也可以不预约，或者第i-1个预约
	dp[i][1] = dp[i-1][0]+nums[i] 					//第i个预约，那么第i-1个只能不预约
*/

type Choose [2]int

func max(i, j int) int {
	if i > j {
		return i
	}

	return j
}

func massage(nums []int) int {
	count := len(nums)
	if count == 0 {
		return 0
	}

	dp := make([]Choose, count+1)

	for i := 1; i <= count; i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1])
		dp[i][1] = dp[i-1][0] + nums[i-1]
	}

	return max(dp[count][0], dp[count][1])

}

```