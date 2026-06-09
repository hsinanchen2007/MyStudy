### 解题思路
每取一行就转一下
如此

### 代码

```golang
func spiralOrder(matrix [][]int) []int {
	var res []int
	l := len(matrix)
	for l > 0 {
        pop := matrix[0]
        res = append(res, pop...)
        if l-1 <= 0 {return res}
        matrix = rotate(matrix[1:], l-1)
        l = len(matrix)
	}
    return res
}

func rotate(matrix [][]int , column int) [][]int {
	row := len(matrix[0])
	res := make([][]int, row)
	for j := 0; j < row; j++ {
		tmp := make([]int, column)
		for i := 0; i < column; i++ {
			tmp[i] = matrix[i][row-j-1]
		}
		res[j] = tmp
	}
	return res
}

```