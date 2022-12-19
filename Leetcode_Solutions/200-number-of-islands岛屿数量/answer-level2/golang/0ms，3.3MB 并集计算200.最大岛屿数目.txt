### 解题思路
此处撰写解题思路

- 从 左到右，从上到下遍历
- 当前为1就先把当前作为一个独立岛屿
- 如果和左边相邻，就合并减去1
- 如果和右边相邻，就合并减去1

### 代码

```golang
func findFatherZip(father []int, i int) int {
	j := i
	for father[i] != i {
		i = father[i]
	}

	father[j] = i
	return i

}

func uniZip(father []int, i, j int) int {
	i = findFatherZip(father, i)
	j = findFatherZip(father, j)
	if i == j {
		return 0
	}
	father[i] = j
	return 1
}

// 每当把独立的岛屿合并，就减少一
func numIslands(grid [][]byte) int {

	m := len(grid)
	if m == 0 {
		return 0
	}

	n := len(grid[0])

	if n == 0 {
		return 0
	}

	father := make([]int, m*n)
	for i := 0; i < m*n; i++ {
		father[i] = i
	}

	var count int
	// for i := 0; i < m; i++ {
	// 	for j := 0; j < n; j++ {
	// 		if grid[i][j] == '0' {
	// 			continue
	// 		}
	// 		father[i*n+j] = i*n + j
	// 		count++
	// 	}
	// }
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '0' {
				continue
			}

			// 先把当前位置作为单独的一个岛屿， 后面如果合并了就再减去
			count++
			ID := i*n + j
			//向上
			if i > 0 && grid[i-1][j] == '1' {
				count = count - uniZip(father, ID, ID-n)
			}
			// 向左
			if j > 0 && grid[i][j-1] == '1' {
				count = count - uniZip(father, ID, ID-1)
			}
		}

	}

	return count
}
```