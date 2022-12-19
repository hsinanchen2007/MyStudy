
每次遇到奇数。记录他前面的偶数个数（从上一个奇数开始的偶数）
```
func numberOfSubarrays(nums []int, k int) int {
	dp := make([]int, 0)
	cnt, ret := 0, 0
	for i := 0; i < len(nums); i++ {
		cnt++
		if nums[i]%2 == 1 {
			dp = append(dp, cnt)
			cnt = 0
		}
		if len(dp) >= k {
			ret += dp[len(dp) - k]
		}
	}
	return ret
}

```
