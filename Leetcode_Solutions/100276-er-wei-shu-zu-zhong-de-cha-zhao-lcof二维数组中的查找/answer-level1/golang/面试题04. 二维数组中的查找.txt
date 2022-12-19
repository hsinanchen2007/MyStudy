### 解题思路
奥利给 老铁！

### 代码

```golang
func findNumberIn2DArray(matrix [][]int, target int) bool {
	// 1.列数据为0
	if len(matrix) == 0 {
		return false
	}
	// 2.里面的行数据为0
	if len(matrix) == 1 && len(matrix[0]) == 0 {
		return false
	}
	rows := len(matrix[0])
	column := len(matrix)
	count := 0
	// 找到比target小的数字
	for i := 0; i < rows; i++ {
		if target >= matrix[0][i] {
			count ++
		}
	}
	// 开始循环就完了 ,老fe
	for i := 0; i < count; i++ {
		for j := 0; j < column; j++ {
			if matrix[j][i] == target {
				return true
			}
		}
	}
	return false

}
```