````
func isValid(s string) bool {
	var stack []string
	m := map[string]string{
		"(": ")",
		"[": "]",
		"{": "}",
	}
	for _, v := range s {
		strV := string(v)
		if strV == "{" || strV == "(" || strV == "[" {
			stack = append(stack, strV)
		} else if len(stack) != 0 && strV == m[stack[len(stack) - 1]] {
			stack = stack[:len(stack) - 1]
		} else {
			return false
		}
	}
	return len(stack) == 0
}
````