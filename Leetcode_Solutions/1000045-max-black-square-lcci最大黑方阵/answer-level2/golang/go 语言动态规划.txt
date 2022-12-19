这个题很繁琐，做了一个多小时，才ac。

基本思想两个数组 dpLength[i][j] 保存(i, j)左边的长度，包括该点
dpWidth[i][j] 保存(i, j)上面的长度，包括该点

```go
func findSquare(matrix [][]int) []int {
	dpLength := make([][]int, len(matrix))
	dpWidth := make([][]int, len(matrix))

	result := make([]int, 0)
	for i := 0; i < len(matrix); i++ {
		dpWidth[i] = make([]int, len(matrix[0]))
		dpLength[i] = make([]int, len(matrix[0]))
	}

	for i := 0; i < len(matrix); i++ {
		if matrix[i][0] == 0 {
			if len(result) == 0 {
				result = []int{i, 0, 1}
			}
			dpLength[i][0] = 1
			if i >= 1 {
				dpWidth[i][0] = dpWidth[i-1][0] + 1
			} else {
				dpWidth[i][0] = 1
			}
		}
	}

	for i := 0; i < len(matrix[0]); i++ {
		if matrix[0][i] == 0 {
			if len(result) == 0 {
				result = []int{0, i, 1}
			}
			dpWidth[0][i] = 1
			if i >= 1 {
				dpLength[0][i] = dpLength[0][i-1] + 1
			} else {
				dpLength[0][i] = 1
			}
		}
	}

	maxL := 0

    if len(result) == 3 {
        maxL = 1
    }

	for i := 1; i < len(matrix); i++ {
		for j := 1; j < len(matrix[0]); j++ {
			if matrix[i][j] == 0 {
				l := min(dpWidth[i-1][j], dpLength[i][j-1]) + 1
				length := 1
				dpLength[i][j] = dpLength[i][j-1] + 1
				dpWidth[i][j] = dpWidth[i-1][j] + 1

				for k := l; k >= 1; k-- {
					if dpLength[i-k+1][j] >= k && dpWidth[i][j-k+1] >= k {
						length = k
                        break
					} 
				}
                
				if maxL < length {
					result = []int{i-length+1, j-length+1, length}
                    maxL = length
				} else if maxL == length {
					if len(result) == 3 {
						if result[0] > i-length+1 {
							result = []int{i-length+1, j-length+1, length}
						} else if result[0] == i-length+1 && result[1] > j-length+1 {
							result = []int{i-length+1, j-length+1, length}
						}
					}
				}

			}
		}
	}
	return result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

```