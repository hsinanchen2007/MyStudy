dp[i][j]表示第i个数的时候，mod 3==j 的最大值

```golang
func maxSumDivThree(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	maxSum := 0 // 记录最大和

	dp := make([][3]int, len(nums))
	dp[0][nums[0]%3] = nums[0]

	if nums[0]%3 == 0 {
		maxSum = nums[0]
	}

	for i := 1; i < len(nums); i++ {
		_dp := dp[i-1] 
		for j := 0; j < 3; j++ {
			sum := dp[i-1][j] + nums[i]
			mod := sum % 3
			_dp[mod] = max(_dp[mod], sum)
		}

		dp[i] = _dp

		if dp[i][0] > maxSum {
			maxSum = dp[i][0]
		}
	}

	return maxSum
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

```