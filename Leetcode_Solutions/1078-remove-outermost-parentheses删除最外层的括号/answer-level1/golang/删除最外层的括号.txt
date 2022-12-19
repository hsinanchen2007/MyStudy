### 解题思路
计数

### 代码

```golang
func removeOuterParentheses(S string) string {
	left := 0
	runes := make([]rune, 0, len(S))
	for _, c := range S {
		if c == '(' {
			if left > 0 {
				runes = append(runes, '(')
			}
			left++
		} else {
			if left > 1 {
				runes = append(runes, ')')
			}
			left--
		}
	}
	return string(runes)
}
```