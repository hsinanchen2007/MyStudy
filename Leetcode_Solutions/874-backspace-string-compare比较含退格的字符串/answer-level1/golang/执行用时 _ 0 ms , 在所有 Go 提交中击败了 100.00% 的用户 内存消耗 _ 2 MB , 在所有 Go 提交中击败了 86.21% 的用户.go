
不是#出栈，如果栈中有数据，否则进栈

```
func backspaceCompare(S string, T string) bool {

	s := back(S)
	t := back(T)
	if s != t {
		return false
	}
	return true
}

func back(s string) string {
	var stack []byte
	sLen := len(s)
	if sLen == 0 {
		return ""
	}
	for i := 0; i < sLen; i++ {
		if s[i] != '#' {
			stack = append(stack, s[i])
			continue
		}
		if len(stack) > 0 {
			stack = stack[:len(stack)-1]
		}
	}

	builder := strings.Builder{}
	builder.Write(stack)
	return builder.String()
}

```
