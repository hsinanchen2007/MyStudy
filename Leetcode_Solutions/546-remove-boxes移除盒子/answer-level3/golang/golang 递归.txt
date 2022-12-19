```
func removeBoxes(boxes []int) int {
	n := len(boxes)
	memo := make([]map[int]map[int]int, n)
	return dfs(boxes, memo, 0, n-1, 0)
}

func dfs(boxes []int, memo []map[int]map[int]int, l, r, k int) int {
	if l > r {
		return 0
	}
	if memo[l][r][k] != 0 {
		return memo[l][r][k]
	}
	for r > l && boxes[r] == boxes[r-1] {
		r--
		k++
	}
	if memo[l] == nil {
		memo[l] = make(map[int]map[int]int)
	}
	if memo[l][r] == nil {
		memo[l][r] = make(map[int]int)
	}
	memo[l][r][k] = dfs(boxes, memo, l, r-1, 0) + (k+1)*(k+1)
	for i := l; i < r; i++ {
		if boxes[i] == boxes[r] {
			mid := dfs(boxes, memo, l, i, k+1) + dfs(boxes, memo, i+1, r-1, 0)
			if memo[l][r][k] < mid {
				memo[l][r][k] = mid
			}

		}
	}
	return memo[l][r][k]
}
```
