```golang
func firstUniqChar(s string) int {
    if len(s) <= 0 {
        return -1
    }
	m := make(map[uint8]int)
	for i := range s {
		m[s[i]]++
	}
	for i := range s {
		if m[s[i]] == 1 {
			return i
		}
	}
	return -1
}

```
