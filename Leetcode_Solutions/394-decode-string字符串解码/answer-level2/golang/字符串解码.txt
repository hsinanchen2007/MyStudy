### 解题思路
记录括号的层次深度

### 代码

```golang
type Comp struct {
	str   string
	cnt   int
	depth int
}

func decodeString(s string) string {
	stack := make([]Comp, 0)

	result := ""
	ns := -1
	depth := 0
	for idx, c := range s {
		switch c {
		case '[':
			count, _ := strconv.Atoi(s[ns:idx])
			ns = -1
			stack = append(
				stack,
				Comp{
					str:   "",
					cnt:   count,
					depth: depth,
				})
			depth++
		case ']':
			l := len(stack) - 1
			if stack[l].depth > 0 {
				comp := stack[l]
				stack = stack[0:l]
				l--
				strs := make([]string, 0, comp.cnt)
				for comp.cnt > 0 {
					strs = append(strs, comp.str)
					comp.cnt--
				}
				stack[l].str = stack[l].str + strings.Join(strs, "")
			} else {
				comp := stack[l]
				stack = stack[:l]
				l--
				strs := make([]string, 0, comp.cnt)
				for comp.cnt > 0 {
					strs = append(strs, comp.str)
					comp.cnt--
				}
				result = result + strings.Join(strs, "")
			}
			depth--
		default:
			if c >= '0' && c <= '9' {
				if ns == -1 {
					ns = idx
				}
			} else {
				if depth > 0 {
					stack[len(stack)-1].str = stack[len(stack)-1].str + string(c)
				} else {
					result = result + string(c)
				}
			}
		}
	}

	return result
}

```