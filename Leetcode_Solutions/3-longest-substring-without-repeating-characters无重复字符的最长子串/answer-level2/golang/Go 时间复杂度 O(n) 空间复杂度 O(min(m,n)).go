```go
func lengthOfLongestSubstring(s string) int {
	strTmp := make(map[byte]int)

	left := -1
	max := 0
	l := len(s)

	for i := 0; i < l; i++ {
		char := s[i]

		if index, ok := strTmp[char]; ok && index > left {
			left = index
		}

		if count := i - left; count > max {
			max = count
		}

		strTmp[char] = i
	}

	return max
}
```
