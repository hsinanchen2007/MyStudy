### 解题思路
逆向工作法

### 代码

```golang
func decodeAtIndex(S string, K int) string {
	size := 0
	for _, c := range S {
		if unicode.IsDigit(c) {
			size *= int(c - '0')
		} else {
			size++
		}
	}
	for i := len(S) - 1; i >= 0; i-- {
		c := rune(S[i])
		K %= size
		if K == 0 && unicode.IsLetter(c) {
			return string(c)
		}
		if unicode.IsDigit(c) {
			size /= int(c - '0')
		} else {
			size--
		}
	}
	return ""
}
```