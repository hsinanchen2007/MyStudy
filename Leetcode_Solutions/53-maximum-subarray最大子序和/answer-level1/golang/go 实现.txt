### 解题思路

// 不能直白的把结果求出来  
//本质的原因  dp[i] 标识按照i  相邻的

### 代码

```golang
package main

import "math"


func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}
	var dp = make([]int, len(nums))
	dp[0] = nums[0]
	for i := 1; i < len(nums); i++ {
		dp[i] = int(math.Max(float64(dp[i-1]+nums[i]), float64(nums[i])))
	}
	var res = dp[0]
	for i := 0; i < len(dp); i++ {
		if res < dp[i] {
			res = dp[i]
		}
	}
	return res
}

```