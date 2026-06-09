```go
func removeOuterParentheses(S string) string {
	var index, start int
	var res []rune
	for i, v := range S {
		if v == '(' {
			index++
		} else {
			index--
		}
		if index == 0 {
			res = append(res, []rune(S[start+1:i])...)
			start = i + 1
		}
	}
	return string(res)
}