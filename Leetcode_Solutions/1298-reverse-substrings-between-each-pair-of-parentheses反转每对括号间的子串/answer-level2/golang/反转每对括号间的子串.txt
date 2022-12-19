### 解题思路
遇')'就逆转

### 代码

```golang
func reverseParentheses(s string) string {
	index := make([]int, 0)
	runes := make([]rune, len(s))
	for i, c := range s {
		runes[i] = c
		if c == ')' {
			reverseString(&runes, index[len(index)-1], i - 1)
			index = index[:len(index)-1]
		} else if c == '(' {
			index = append(index, i+1)
		}
	}
	i := 0
	for _, c:=range runes {
		if c != '(' && c != ')' {
			runes[i] = c
			i++
		}
	}
	return string(runes[:i])
}

func reverseString(runes *[]rune, s int, e int) {
	for s < e {
		r := (*runes)[e]
		(*runes)[e] = (*runes)[s]
		(*runes)[s] = r
		s++
		e--
	}
}

```