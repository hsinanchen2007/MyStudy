```go
func isPalindrome(s string) bool {
	n := len(s)
	if n <= 1 {
		return true
	}

	i := 0
	j := n - 1

	for i < j {
		ci := s[i]
		cj := s[j]
		if !isAlphabet(ci) && !isNumber(ci) {
			i++
			continue
		}
		if !isAlphabet(cj) && !isNumber(cj) {
			j--
			continue
		}

		if isNumber(ci) && ci != cj {
			return false
		}

		if isAlphabet(ci) {
			if isAlphabet(cj) {
				if !charEqual(int(ci), int(cj)) {
					return false
				}
			} else {
				return false
			}
		}

		i++
		j--
	}
	return true
}

func isAlphabet(c byte) bool {
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'
}

func isNumber(c byte) bool {
	return c >= '0' && c <= '9'
}

func charEqual(a, b int) bool {
	return a-b == 0 || a-b == 32 || a-b == -32
}
```