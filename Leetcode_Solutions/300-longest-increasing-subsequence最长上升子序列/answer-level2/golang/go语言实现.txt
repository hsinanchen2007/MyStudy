### 解题思路
1、动态规划的思想  ， dp[i] 表示的 按照i结尾的最长的

### 代码

```golang
package main

import (
	"fmt"
	"math"
)

//最长上升子序列
//f [i]是 表示  按照 i 结尾的最大的长度

var mapHelp map[int]float64

func lengthOfLIS(nums []int) int {
	mapHelp = make(map[int]float64)
	if len(nums) <= 1 {
		return len(nums)
	}
	var res float64
	for i := 0; i < len(nums); i++ {
		res = math.Max(res, getLIS(nums, i))
	}
	return int(res)
}

func getLIS(nums []int, curDealIndex int) float64 {
	if curDealIndex == 0 {
		return 1
	}
	if _, ok := mapHelp[curDealIndex]; ok {
		return mapHelp[curDealIndex]
	}
	var res = 1.0
	for i := 0; i <= curDealIndex; i++ {
		if nums[curDealIndex] > nums[i] {
			res = math.Max(res, getLIS(nums, i)+1)
		}
	}
	mapHelp[curDealIndex] = res

	return res
}

```