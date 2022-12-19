坐标直接计算
```
func rotate(matrix [][]int)  {
    length := len(matrix) - 1
	if length == -1 {
		return
	}

	for i := 0; i < (length+1)/2; i++ {
		for j := i; j < length-i; j++ {
			matrix[i][j], matrix[j][length-i], matrix[length-i][length-j], matrix[length-j][i] =
				matrix[length-j][i], matrix[i][j], matrix[j][length-i], matrix[length-i][length-j]

		}
	}
}
```


