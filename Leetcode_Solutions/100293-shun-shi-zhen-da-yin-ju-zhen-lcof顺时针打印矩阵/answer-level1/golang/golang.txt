### 解题思路

两个指针，判断边界问题即可

### 代码

```golang
func spiralOrder(matrix [][]int) []int {
    if matrix == nil || len(matrix) == 0 || len(matrix[0]) == 0 {
        return []int{}
    }
	m, n := len(matrix), len(matrix[0])
	res := []int{}
	for i := 0; i < (min(m,n)+1)  >> 1; i++ {
		res = append(res, printMatrix(matrix, i)...)
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a 
	}
	return b 
}

func printMatrix(matrix [][]int, level int) []int {
	m, n := len(matrix) - 1-level, len(matrix[0]) - 1 - level
	x, y := level, level
	res := []int{}
	
	for y <= n {
		res = append(res, matrix[x][y])
		y++
	}
	y--
	x++
    if x > m {
		return res
	}
	for x <= m {
		res = append(res, matrix[x][y])
		x++
	}
	x--
	y--
    if y  <level {
        return res
    }
	for y >= level {
		res = append(res, matrix[x][y])
		y--
	}
	y++
	x--
  
	for x > level {
		res = append(res, matrix[x][y])
		x--
	}
	return res
}
```