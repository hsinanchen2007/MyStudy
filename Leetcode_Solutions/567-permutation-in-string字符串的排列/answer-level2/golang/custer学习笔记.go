```go
func checkInclusion(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}
	hash := [26]int{}
	for i := 0; i < len(s1); i++ {
		hash[s1[i]-'a']++
	}
	l, count := 0, 0
	for r := 0; r < len(s2); r++ {
		hash[s2[r]-'a']--
		if hash[s2[r]-'a'] >= 0 {
			count++
		}
		if r >= len(s1) {
			hash[s2[l]-'a']++
			if hash[s2[l]-'a'] >= 1 {
				count--
			}
			l++
		}
		if count == len(s1) {
			return true
		}
	}
	return false
}
```