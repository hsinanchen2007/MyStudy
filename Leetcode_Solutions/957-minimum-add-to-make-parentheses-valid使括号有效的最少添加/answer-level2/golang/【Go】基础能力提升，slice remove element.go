```
func minAddToMakeValid(S string) int {
	stack := make([]byte, 0)
	for i, c := range S {
		if len(stack) > 0 && stack[len(stack) - 1] == '('  && c == ')' {
			stack = stack[0 : len(stack) -1]
			continue
		}
		stack = append(stack, S[i])
	}
	return len(stack)
}
```
