### 解题思路
先确定最小值最大值 在区间内递增搜索 每次搜索用二分查找

### 代码

```golang

func smallestCommonElement(mat [][]int) int {
	row := len(mat)
	col := len(mat[0])
	hi := math.MaxInt32
	lo := math.MinInt32
	for i := 0; i < row; i++ {
		if lo < mat[i][0] {
			lo = mat[i][0]
		}
		if hi > mat[i][col-1] {
			hi = mat[i][col-1]
		}
	}

	for i := lo; i <= hi; i++ {
		if possible(mat, row, col, i) {
			return i
		}
	}

	return -1

}

func possible(mat [][]int, row, col, elem int) bool {
	for i := 0; i < row; i++ {
		if !binaryFind(mat[i], elem) {
			return false
		}
	}
	return true
}

func binaryFind(row []int, elem int) bool {
	lo := 0
	hi := len(row) - 1
	for lo < hi {
		middle := (lo + hi) / 2
		if row[middle] > elem {
			hi = middle
		} else if row[middle] < elem {
			lo = middle + 1
		} else {
			return true
		}
	}
	if row[lo] == elem {
		return true
	}

	return false
}

```