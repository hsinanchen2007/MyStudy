```
func numJewelsInStones(J string, S string) int {
	var result int
	m := make(map[rune]bool)
	for _, j := range J {
		m[j] = true
	}

	for _, s := range S {
		if _, ok := m[s]; ok {
			result++
		}
	}
	return result
}
```
