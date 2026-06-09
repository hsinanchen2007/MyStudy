### 解题思路

参考了官方题解，深度优先遍历：向每个1的四个方向探索，探索的土地连起来就是面积，将探索过的土地置为0，防止多次探索。

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
	ans := 0
	for i := 0;i < len(grid);i++ {
		for j := 0;j < len(grid[0]);j++ {
			ans = max(ans, dfs(grid, i, j))
		}
	}
	return ans
}
func dfs(grid [][]int,cur_i int,cur_j int) int {
	if cur_i < 0 || cur_j < 0 || cur_i == len(grid) || cur_j == len(grid[0]) || grid[cur_i][cur_j] != 1 {
		return 0
	}
	grid[cur_i][cur_j] = 0
	di := []int{0, 0, 1, -1}
	dj := []int{1, -1, 0, 0}
	ans := 1
	for i := 0; i != 4;i++ {
		next_i := cur_i + di[i]
		next_j := cur_j + dj[i]
		ans += dfs(grid, next_i, next_j)
	}
	return ans
}
func max(a int,b int) int {
	if a > b {
		return a
	}else {
		return b
	}
}
```