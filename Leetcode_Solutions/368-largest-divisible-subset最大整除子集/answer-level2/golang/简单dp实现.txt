数组先排序，先排序，先排序，如果数组是有序的，很容易就可以用dp求解了


```golang
func largestDivisibleSubset(nums []int) []int {
	if len(nums) == 0 {
		return nil
	}
	sort.Ints(nums)
	dp := make([][]int, len(nums))
	dp[0] = append(dp[0], nums[0])
	for i := 1; i < len(nums); i++ {
		for j := i - 1; j >= 0; j-- {
			if nums[i]%nums[j] == 0 {
				if len(dp[j])+1 > len(dp[i]) {
					dp[i] = append(dp[j], nums[i])
				}
			}
		}
		if len(dp[i]) == 0 {
			dp[i] = []int{nums[i]}
		}
	}

	m := 0
	for i := 1; i < len(nums); i++ {
		if len(dp[i]) > len(dp[m]) {
			m = i
		}
	}

	return dp[m]

}
```