> 解题思路：
m x n 矩阵

按题意，顺时针顺序对矩阵进行遍历；每次遍历都转一圈，每一行或列遍历完后，更新边界值，并且判断是否结束。

1. 定义好上下左右边界初始值；up = 0; d = m-1; l = 0;
2. 假设当前点为(i, j)
3. 遍历顺序： 左->右(u, j+1),完成后up++； 上->下(i+1, r),完成后r--；右->左(d, j-1),完成后d--；下->上(i-1, l),完成后l++


```golang
func spiralOrder(matrix [][]int) []int {
	// 判断特殊值
	if matrix == nil || len(matrix) == 0 {
		return []int{}
	}

	m, n := len(matrix), len(matrix[0])
	up, down, left, right := 0, m-1, 0, n-1
	var result []int

	for {
		// 左->右
		for i := left; i <= right; i++ {
			result = append(result, matrix[up][i])
		}
		if up++; up > down {
			break
		}

		// 上->下
		for i := up; i <= down; i++ {
			result = append(result, matrix[i][right])
		}
		if right--; right < left {
			break
		}

		// 右->左
		for i := right; i >= left; i-- {
			result = append(result, matrix[down][i])
		}
		if down--; down < up {
			break
		}

		// 下->上
		for i := down; i >= up; i-- {
			result = append(result, matrix[i][left])
		}
		if left++; left > right {
			break
		}
	}

	return result
}
```