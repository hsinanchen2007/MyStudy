找最后一列，第一个大于target的行，再找第一列最后一个小于target的行，target一定在这两个行之间的行中（包含找到的两行），在每一行中不停的二分查找
```
func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}
	if len(matrix) == 1 && len(matrix[0]) == 0 {
		return false
	}
	rowLen := len(matrix[0])
	columnLen := len(matrix)

	start, end := 0, len(matrix)-1
	mid1 := start + (end-start)>>1
	for start <= end {
		mid1 = start + (end-start)>>1
		if matrix[mid1][rowLen-1] == target {
			return true
		} else if matrix[mid1][rowLen-1] > target {
			if mid1 == 0 || matrix[mid1-1][rowLen-1] < target {
				break
			}
			end = mid1 - 1
		} else {
			start = mid1 + 1
		}
	}
	start, end = 0, len(matrix)-1
	mid2 := start + (end-start)>>1
	for start <= end {
		mid2 = start + (end-start)>>1
		if matrix[mid2][0] == target {
			return true
		} else if matrix[mid2][0] < target {
			if mid2 == columnLen-1 || matrix[mid2+1][0] > target {
				break
			}
			start = mid2 + 1
		} else {
			end = mid2 - 1
		}
	}

	for i:= mid1; i <= mid2; i++ {
		start, end = 0, len(matrix[i])-1
		for start <= end {
			mid := start + (end-start)>>1
			if matrix[i][mid] == target {
				return true
			}else if matrix[i][mid] > target {
				end = mid - 1
			}else {
				start = mid + 1
			}
		}
	}
	return false
}
```
