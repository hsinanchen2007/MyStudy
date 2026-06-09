### 解题思路
- dp[i] = nums[i] - nums[i-1] == nums[i-1] - nums[i-2] ? dp[i-1] + 1 : 0
- return sum(dp)


### 代码

```golang
func numberOfArithmeticSlices(A []int) int {
    return method_dp(A)
}

/*
//记录详细等差数组
i = 2; i...
	nums[i] - nums[i-1] == nums[i-1] - nums[i-2]
		dp[i].push([nums(i), nums(i-1), nums(i-2)])
			dp[i-1]...
				dp[i].push(dp[i-1][j].push(nums[i]))

dp...
	dp[i]...
		res.push(dp[i][j])

return res

//只记录等差数组数量
i = 2; i...
	nums[i] - nums[i-1] == nums[i-1] - nums[i-2]
		dp[i] = dp[i-1] + 1

return sum(dp)
*/
func method_dp(nums []int) int {
    sum := 0
    dp := make([]int, len(nums))
    for i := 2; i < len(nums); i++ {
        if nums[i] - nums[i-1] == nums[i-1] - nums[i-2] {
            dp[i] = dp[i-1] + 1
            sum += dp[i]
        }
    }
    return sum
}
```