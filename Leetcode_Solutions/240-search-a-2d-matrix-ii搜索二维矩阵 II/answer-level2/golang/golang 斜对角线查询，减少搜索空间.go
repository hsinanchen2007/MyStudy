### 解题思路
先求出矩阵的秩，然后按照对角线查找比自己大的第一个元素（设为matrix[i][i]），若能找到，则说明查询的值若存在的话，则应该位于matrix[0~i][i]或matrix[i][0~i]上，若找不到，则说明元素不存在。

### 代码
执行用时 :32 ms, 在所有 Go 提交中击败了66.88%的用户
内存消耗 :6.3 MB, 在所有 Go 提交中击败了75.28%的用户

```golang

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}
	if len(matrix[0]) == 0 {
		return false
	}
	minL, maxL := len(matrix), len(matrix[0])
	if minL > maxL {
		minL, maxL = maxL, minL
	}
	for i := 0; i <minL ;i++ {
		if matrix[i][i] == target {
			return true
		}else if matrix[i][i] < target {
			continue
		}else{
			for j := 0; j < minL; j++ {
				if matrix[j][i] == target || matrix[i][j] == target{
					return true
				}
			}
		}
	}
	for i := minL; i < maxL; i++ {
		if (minL == len(matrix) && matrix[minL-1][i] >= target){
			if matrix[minL-1][i] == target {
				return true
			}
			for j := 0; j < minL; j++ {
				if matrix[j][i] == target {
					return true
				}
			}
		}else if (minL == len(matrix[0]) && matrix[i][minL-1] >= target) {
			if matrix[i][minL-1]  == target {
				return true
			}
			for j := 0; j < minL; j++ {
				if matrix[i][j] == target {
					return true
				}
			}
		}
	}
	return false
}

```