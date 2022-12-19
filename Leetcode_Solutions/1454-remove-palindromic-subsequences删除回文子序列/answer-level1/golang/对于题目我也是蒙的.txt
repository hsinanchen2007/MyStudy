```
func removePalindromeSub(s string) int {
	var (
		i      int
		count  = 1
		length = len(s)
	)
	switch length {
	case 0:
		return 0
	case 1:
		return 1
	default:
		for i = 0; i < length/2; i++ {
			if s[i] != s[length-1-i] {
				goto CHECK
			}
		}
		return 1
	CHECK:
		for i = 1; i < length; i++ {
			if s[i] == s[0] {
				count++
			}
		}
		if count == length {
			return 1
		}
		return 2
	}

}
```
