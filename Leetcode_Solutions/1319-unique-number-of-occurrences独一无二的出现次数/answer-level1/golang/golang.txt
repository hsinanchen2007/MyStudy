```
func uniqueOccurrences(arr []int) bool {
    m := make(map[int]int)

	for _, a := range arr {
		m[a] += 1
	}

	m2 := make(map[int]bool)
	for _, v := range m {
		if _, ok := m2[v]; ok {
			return false
		}
		m2[v] = true
	}

	return true
}
```