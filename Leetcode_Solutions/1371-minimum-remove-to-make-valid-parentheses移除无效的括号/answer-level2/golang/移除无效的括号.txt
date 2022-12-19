### 解题思路
先从左往右移除多余的')', 再从右往左移除多余的'('.

### 代码

```golang
func minRemoveToMakeValid(s string) string {
	runes := make([]rune, 0, len(s))
	left := 0
	// 清楚多余的')'
	for _, c := range s {
		if c == '(' {
			runes = append(runes, c)
			left++
		} else if c == ')' {
			if left > 0 {
				runes = append(runes, c)
				left--
			}
		} else {
			runes = append(runes, c)
		}
	}
	// 清楚多余的'('
	i := len(runes)
	for j := len(runes) - 1; j >= 0; j-- {
		if runes[j] == '(' && left > 0 {
			left--
		} else {
			i--
			runes[i] = runes[j]
		}
	}
	return string(runes[i:])
}
```