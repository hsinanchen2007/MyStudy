执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.1 MB, 在所有 Go 提交中击败了48.88%的用户

```
func isValid(s string) bool {
	stack := make([]byte, 0)
	symbolMap := map[byte]byte{'}' : '{', ']' : '[', ')' : '('}
	var val byte; var ok bool
	for i:=0; i<len(s); i++ {
		if val, ok = symbolMap[s[i]]; ok {
			// 判断匹配
			if len(stack) == 0 || stack[len(stack) - 1] != val {
				return false
			}
			// pop
			stack = stack[0:len(stack)-1]
		} else {
			// push
			stack = append(stack, s[i])
		}
	}
	return len(stack) == 0
}
```
