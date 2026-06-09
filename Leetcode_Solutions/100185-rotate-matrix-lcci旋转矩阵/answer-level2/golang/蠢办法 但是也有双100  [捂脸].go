直接遍历赋值到新的矩阵，最后再赋值回去原矩阵
```
func rotate(matrix [][]int)  {
    length := len(matrix)
	var tempMatrix [][]int
	for j := 0; j < length; j++ {
		var temp []int
		for i := length - 1; i >= 0; i-- {
			temp = append(temp, matrix[i][j])
		}
		tempMatrix = append(tempMatrix, temp)
	}
	
	for i := 0; i < length; i++ {
		for j := 0; j < length; j++ {
			matrix[i][j] = tempMatrix[i][j]
		}
	}
}
```
