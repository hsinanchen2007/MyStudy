### 解题思路
联系到括号其实就是进栈出栈, 问题就迎刃而解了

### 代码

```golang
func isValid(s string) bool {
	var stack = make([]rune, 0, 20)
	var ss = []rune(s)
	for _, c := range ss {
		switch c {
		case '(', '[', '{':
			stack = append(stack, c)
		case ')':
            l := len(stack)-1
            if l<0{
                return false
            }
			if stack[l] == '(' {
				stack = stack[0 : l]
			} else {
				return false
			}
		case ']':
            l := len(stack)-1
            if l<0{
                return false
            }
			if stack[l] == '[' {
				stack = stack[0 : l]
			} else {
				return false
			}
		case '}':
            l := len(stack)-1
            if l<0{
                return false
            }
			if stack[l] == '{' {
				stack = stack[0 : l]
			} else {
				return false
			}
		default:
			return false
		}
	}

	if len(stack) == 0 {
		return true
	} else {
		return false
	}
}
```