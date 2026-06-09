
### 代码

```golang
func shiftGrid(grid [][]int, k int) [][]int {
    row, line := len(grid), len(grid[0])
	length := row * line
	s := make([]int, length)
	i := 0
	for _, v := range grid {
		for _, v2 := range v {
			s[i] = v2
			i++
		}
	}
	k %= length
	j := length - k
	var newS []int
	newS = append(newS, s[j:]...)
	newS = append(newS, s[:j]...)

	index := 0
	for i := 0; i < row; i++ {
		for j := 0; j < line; j++ {
			grid[i][j] = newS[index]
			index++
		}
	}
	return grid
}
```