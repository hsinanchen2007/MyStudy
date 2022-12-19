### 解题思路
此处撰写解题思路
![截屏2020-03-15下午7.42.51.png](https://pic.leetcode-cn.com/74891a4b4fbe6404f605a386b3dd49081d8f1fda456e1ee6438dbbe5ca119414-%E6%88%AA%E5%B1%8F2020-03-15%E4%B8%8B%E5%8D%887.42.51.png)

### 代码

```golang
func maxAreaOfIsland(grid [][]int) int {
	n := 0
	for i,_ := range grid {
		for j,_ := range grid[i]{
			if grid[i][j] == 1 {
				x := search(grid,i,j,0)
				if x > n {
					n = x
				}
			}
		}
	}

	return n
}

func search(grid [][]int,i,j,n int) int {
	grid[i][j] = 0

	//寻找 上 下 左 右 是否有等于一的
	// 先判断是否超出

	// 上
	if i > 0 && j <= len(grid[i-1])-1 && grid[i-1][j] == 1 {
		n = search(grid,i-1,j,n)
	}

	// 下
	if i+1 < len(grid) && j <= len(grid[i+1])-1 && grid[i+1][j] == 1 {
		n = search(grid,i+1,j,n)
	}

	// 左
	if j > 0 && grid[i][j-1] == 1 {
		n = search(grid,i,j-1,n)
	}

	// 右
	if j+1 <= len(grid[i])-1 && grid[i][j+1] == 1{
		n = search(grid,i,j+1,n)
	}

	return n+1
}
```