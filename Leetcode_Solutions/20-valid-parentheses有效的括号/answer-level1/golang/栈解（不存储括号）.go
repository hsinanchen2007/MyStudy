我看好多同学使用了map存储括号，其实利用括号的ASCII码值，更为便捷

```
func isValid(s string) bool {
	stack := make([]rune, 0)
	for _, v := range s {

		if len(stack) == 0 {
			stack = append(stack, v)
			continue
		}
		if v-stack[len(stack)-1] == 1 ||v-stack[len(stack)-1] == 2{
			stack = stack[0:len(stack)-1]
		} else {
			stack = append(stack, v)
		}
	}
	
	if len(stack) == 0 {
		return true
	}
	return false
}
```