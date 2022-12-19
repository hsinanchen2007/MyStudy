### 解题思路

回溯结束条件：可以走到2且矩阵中没有0了 => backTrack函数需要三个参数，当前坐标row, col，当前剩余0的个数zeroCount

### 代码

```golang
var delta     = [4][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

func uniquePathsIII(grid [][]int) int {
	var (
		result    int
		zeroCount int
		backTrack func(row int, col int, zeroCount int)
	)
	startX, startY, rowCount, colCount := 0, 0, len(grid), len(grid[0])
	for i := 0; i < rowCount; i++ {
		for j := 0; j < colCount; j++ {
			if grid[i][j] == 0 {
				zeroCount++
			} else if grid[i][j] == 1 {
				startX, startY = i, j
			}
		}
	}
	backTrack = func(row int, col int, zeroCount int) {
		for i := 0; i < 4; i++ {
			dx := row + delta[i][0]
			dy := col + delta[i][1]
			if 0 <= dx && dx < rowCount && 0 <= dy && dy < colCount {
				if zeroCount == 0 && grid[dx][dy] == 2 {
					result++
					return
				}
				if grid[dx][dy] == 0 {
					grid[dx][dy] = -1
					backTrack(dx, dy, zeroCount-1)
					grid[dx][dy] = 0
				}
			}
		}
	}
	backTrack(startX, startY, zeroCount)
	return result
}
```