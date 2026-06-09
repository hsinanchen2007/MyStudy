### 解题思路
此处撰写解题思路

### 代码

```golang

func maxAreaOfIsland(grid [][]int) int {
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}

	res := 0
	xs, ys := len(grid), len(grid[0])
	for i := 0; i < xs; i++ {
		for j := 0; j < ys; j++ {
			res = max(res, walk(&grid, i, j, xs, ys))
		}
	}

	return res
}

func walk(grid *[][]int, i, j, xs, ys int) int {
	if i < 0 || j < 0 || i >= xs || j >= ys || (*grid)[i][j] == 0 {
		return 0
	}

	(*grid)[i][j] = 0
	cur := 1
	cur += walk(grid, i+1, j, xs, ys)
	cur += walk(grid, i-1, j, xs, ys)
	cur += walk(grid, i, j+1, xs, ys)
	cur += walk(grid, i, j-1, xs, ys)
	return cur
}

func max(i0, i1 int) int {
	if i0 > i1 {
		return i0
	}
	return i1
}
```