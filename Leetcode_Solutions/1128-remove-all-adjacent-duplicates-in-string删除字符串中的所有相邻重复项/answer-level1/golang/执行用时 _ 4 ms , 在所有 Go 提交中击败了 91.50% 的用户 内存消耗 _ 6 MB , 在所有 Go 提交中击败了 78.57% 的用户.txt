```
func removeDuplicates(S string) string {
	var stack []byte
	for i := 0; i <= len(S)-1; i++ {
		if len(stack) == 0 {
			stack = append(stack, S[i])
			continue
		}
		if stack[len(stack)-1] == S[i] {
			stack = stack[:len(stack)-1]
			continue
		}
		stack = append(stack,S[i])
	}
	var build strings.Builder
	build.Write(stack)
	return build.String()
}
```
