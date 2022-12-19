golang, 栈的应用，以slice作栈．

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 栈的应用
// 时间复杂度：O(n)  空间复杂度：O(n)

func isValid(s string) bool {

	var stack []rune
	
	for _, c:=range []rune(s) {
		if c=='(' || c=='[' || c=='{' {
			stack = append(stack, c)  // 若为左半部分括号，则将其入栈
			continue
		}

		if len(stack)==0 {  // 处理右半部分括号数目大于左半部分括号数目的情况,如："{}}}"
			return false
		}

		temp := stack[len(stack)-1]
		stack = stack[:len(stack)-1]  // 栈顶元素出栈，尝试匹配
		if (c==')' && temp!='(') || (c==']' && temp!='[') || (c=='}' && temp!='{') {
			return false
		}
	}

	return len(stack) == 0  //　防止左半部分括号数目大于右半部分括号数目的情况，如："{{{}"
}
```
