### 解题思路
太简单，直接看代码吧。

### 代码

```golang
func countNegatives(grid [][]int) int {
	count := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[i]); j++ {
			if grid[i][j] < 0 {
				count++
			}
		}
	}
	return count
}
```