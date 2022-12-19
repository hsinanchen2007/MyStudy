### 解题思路
1、设置2个数组row int[], column []int，row存储第几行有数字0，column存储第几列有数字0；
2、遍历row数组，分别将数组中存储的这些行（一整行的数字），全部设置为0；
3、遍历column数组，分别将数组中存储的这些列（一整列的数字），全部设置为0；

### 代码

```golang
// 时间复杂度：O(m+n)
func setZeroes(matrix [][]int)  {
	rowLength := len(matrix)
	columnLength := len(matrix[0])
	var row []int	/* row: 行*/
	var column []int	/* column: 列*/
	for i := 0; i < rowLength; i++ {
		for j := 0; j < columnLength; j++ {
			if matrix[i][j] == 0 {
				row = append(row, i)
				column = append(column, j)
			}
		}
	}

	// 将含有0的所有行，全部设置为0
	for _, i := range row {
		for j := 0; j < columnLength; j++ {
			if matrix[i][j] != 0 {
				matrix[i][j] = 0
			}
		}
	}

	for _, i := range column {
		for j := 0; j < rowLength; j++ {
			if matrix[j][i] != 0 {
				matrix[j][i] = 0
			}
		}
	}
}
```