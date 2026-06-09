
```
func minimumTotal(triangle [][]int) int {
	row := len(triangle)
	for level := row - 2; level >= 0; level-- {
		for i := 0; i <= level; i++ { //第i行有i+1个数字
			//取下层相邻两个值中的较小值
			triangle[level][i] = minValue(triangle[level+1][i], triangle[level+1][i+1]) + triangle[level][i]
		}
	}
	return triangle[0][0]
}
func minValue(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```
