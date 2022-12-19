
```go
var min = 1 << 31

func minimumTotal(triangle [][]int) int {
	if len(triangle) == 0 || len(triangle[0]) == 0 {
		return 0
	}
	dfs(triangle, 0, 0, 0)
	return min
}

func dfs(nums [][]int, x, y int, sum int) {
	// x = n 结束
	if x == len(nums) {
		if sum < min {
			min = sum
		}
		return
	}
	if y >= len(nums[x]) {
		return
	}

	dfs(nums, x+1, y, sum+nums[x][y])
	dfs(nums, x+1, y+1, sum+nums[x][y])
}
```