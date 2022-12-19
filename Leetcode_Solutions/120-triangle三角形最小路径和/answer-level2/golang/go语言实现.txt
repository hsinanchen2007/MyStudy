### 解题思路
1、动态规划的思想 
2、dp 从下开始往上面计算

### 代码

```golang
package main

import "fmt"

//三角形最小路径和
//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
func minimumTotal(triangle [][]int) int {
	if len(triangle) == 0 {
		return 0
	}
	var dp [][]int
	for i := 0; i < len(triangle); i++ {
		var oneLineDp []int
		for j := 0; j < len(triangle); j++ {
			oneLineDp = append(oneLineDp, 0)
		}
		dp = append(dp, oneLineDp)
	}
	for i := 0; i < len(dp); i++ {
		dp[len(dp)-1][i] = triangle[len(dp)-1][i]
	}
	for i := len(dp) - 2; i >= 0; i-- {
		for j := 0; j < len(dp[i])-1; j++ {
			if j >= len(triangle[i]) {
				break
			}
			if dp[i+1][j] > dp[i+1][j+1] {
				dp[i][j] = dp[i+1][j+1] + triangle[i][j]
			} else {
				dp[i][j] = dp[i+1][j] + triangle[i][j]
			}
		}
	}
	return dp[0][0]
}
```