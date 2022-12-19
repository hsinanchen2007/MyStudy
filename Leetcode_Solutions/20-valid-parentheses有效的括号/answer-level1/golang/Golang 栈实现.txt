
1. 初始化括号对应的map
2. 循环遍历字符串每一个字符
3. 对于每一个字符，如果是左括号类型，就入栈
4. 如果是右括号类型 1）如果栈空 或者 左括号和右括号不对应 返回false
5. 弹出栈顶元素，继续循环
6. 循环完毕字符串后，判断栈是否为空

```
func isValid(s string) bool {
	var stack []rune
	mp := map[rune]rune{
		'(': ')',
		'[': ']',
		'{': '}',
	}
	for _, v := range s {
		switch v {
		case '(', '[', '{':
			stack = append(stack, v)
		case ')', ']', '}':
			if len(stack) == 0 || mp[stack[len(stack)-1]] != v {
				// 1、栈为空但字符数组还有值 return false
				// 2、栈不空但栈顶和此时字符串不成对应关系
				return false
			}
			// 弹出栈顶元素
			stack = stack[:len(stack)-1]
		}
	}
	return len(stack) == 0
}
```
