### 解题思路
此处撰写解题思路

和 朋友圈 类似

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

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '0' {
				continue
			}

			ID := i*n + j
			//向上
			if i > 0 && grid[i-1][j] == '1' {
				uniZip(father, ID, ID-n)
			}
			// 向左
			if j > 0 && grid[i][j-1] == '1' {
				uniZip(father, ID, ID-1)
			}
		}

	}

	var count int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == '0' {
				continue
			}

			if father[i*n+j] == i*n+j {
				count++
			}

		}

	}
	return count
}

```