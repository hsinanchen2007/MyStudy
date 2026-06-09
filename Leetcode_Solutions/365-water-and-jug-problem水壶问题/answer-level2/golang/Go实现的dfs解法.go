翻了一下没有Go实现的dfs解法，我来补上。
*性能较低，一定没有数学方法来的高喽*

```
var X, Y, Z int

func canMeasureWater(x int, y int, z int) bool {
	X, Y, Z = x, y, z
	m := make(map[[2]int]struct{})
	return dfs(&m, 0, 0)
}

func dfs(m *map[[2]int]struct{}, xCurr, yCurr int) bool {
	if xCurr == Z || yCurr == Z || xCurr+yCurr == Z {
		return true
	}

	if _, exist := (*m)[[2]int{xCurr, yCurr}]; exist {
		return false
	}

	(*m)[[2]int{xCurr, yCurr}] = struct{}{}

	return dfs(m, X, yCurr) ||
		dfs(m, xCurr, Y) ||
		dfs(m, 0, yCurr) ||
		dfs(m, xCurr, 0) ||
		dfs(m, xCurr-min(xCurr, Y-yCurr), yCurr+min(xCurr, Y-yCurr)) ||
		dfs(m, xCurr+min(yCurr, X-xCurr), yCurr-min(yCurr, X-xCurr))
}

func min(i, j int) int {
	if i < j {
		return i
	} else {
		return j
	}
}
```
