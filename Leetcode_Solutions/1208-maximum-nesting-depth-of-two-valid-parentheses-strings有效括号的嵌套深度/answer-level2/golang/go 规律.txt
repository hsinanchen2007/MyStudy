```
func maxDepthAfterSplit(seq string) []int {
	maps := make([]int, len(seq))
	for i := 0; i < len(seq); i++ {
		if seq[i] == '(' {
			maps[i] = i % 2
		} else {
			maps[i] = 1 - i%2
		}
	}
	return maps
}
```
