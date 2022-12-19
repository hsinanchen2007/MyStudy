```go
func removeOuterParentheses(S string) string {
	size, i, res, l := len(S), 0, "", 0
	for i < size {
		if S[i] == '(' {
			l += 1
			for j := i + 1; j < size; j++ {
				if S[j] == '(' {
					l += 1
				} else {
					l -= 1
				}
				if l == 0 {
					res += string(S[i+1 : j])
					i = j + 1
					break
				}
			}
		} else {
			break
		}
	}
	return res
}
```
