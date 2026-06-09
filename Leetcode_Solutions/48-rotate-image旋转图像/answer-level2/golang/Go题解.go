思路：先水平翻转，再对角线翻转。
```
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.7 MB, 在所有 Go 提交中击败了63.93%的用户
```
```Go []
func rotate(matrix [][]int) {
	for i := 0; i < len(matrix)/2; i++ {
		for j := range matrix[i] {
			matrix[i][j], matrix[len(matrix)-1-i][j] = matrix[len(matrix)-1-i][j], matrix[i][j]
		}
	}
	for i := 0; i < len(matrix)-1; i++ {
		for j := i + 1; j < len(matrix[i]); j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}
```
[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)