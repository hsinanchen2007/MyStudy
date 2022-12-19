注意到第i行：
共i+1个元素；
两侧元素都是1；
其他每个元素都是上一行对齐的元素与对齐元素前一个元素的和，即f(i,j) = f(i-1, j-1) + f(i-1)(j)；
左右对称，即f(i，j) = f(i, i-j)

时间复杂度，O((1+2+...+n)/2) = O((1+n)*n/4) = O(n^2) // 每行只遍历一半数目
空间复杂度都是O(1+2+...+n) = O((1+n)*n/2) = O(n^2)

```
func generate(numRows int) [][]int {
	if numRows < 1 {
		return nil
	}
	if numRows == 1 {
		return [][]int{{1}}
	}
	if numRows == 2 {
		return [][]int{{1}, {1, 1}}
	}
	result := make([][]int, numRows)
	result[0], result[1] = []int{1}, []int{1, 1}
	for i := 2; i < numRows; i++ {
		tmp := make([]int, i+1)
		tmp[0], tmp[i] = 1, 1
		for j := 1; j <= (i+1)/2; j++ {
			value := result[i-1][j-1] + result[i-1][j]
			tmp[j], tmp[i-j] = value, value
		}
		result[i] = tmp
	}
	return result
}
```