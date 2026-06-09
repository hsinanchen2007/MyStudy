26 分钟前	通过	0 ms	2 MB	Golang

`func isValid(src string) bool {
	s := []byte(src)
	//用切片的索引表示栈  i为栈顶元素的索引 -1即为栈空
	stack := make([]byte, len(s))
	index := -1

	var buf byte
	for i := 0; i < len(s); i++ {
		buf = s[i]
		if buf == '(' || buf == '[' || buf == '{' {
			//将左括号直接压栈
			index++
			stack[index] = buf
			// printStack(stack, index)
			continue
		}
		if buf == ')' || buf == ']' || buf == '}' {
			//当前栈内无元素 必定无法匹配
			if index < 0 {
				return false
			}
			//右括号判断是否匹配并出栈
			if buf == ')' && stack[index] == '(' {
				//出栈
				// fmt.Println("匹配) 出栈")
				index--
				// printStack(stack, index)
				continue
			}
			if buf == ']' && stack[index] == '[' {
				//出栈
				// fmt.Println("匹配] 出栈")
				index--
				// printStack(stack, index)
				continue
			}
			if buf == '}' && stack[index] == '{' {
				//出栈
				// fmt.Println("匹配} 出栈")
				index--
				// printStack(stack, index)
				continue
			}
			//此右括号未匹配
			// fmt.Println("右括号未匹配")
			return false

		}
	}
	// fmt.Println("最终栈内")
	// printStack(stack, index)
	//判断栈内是否为空
	if index == -1 {
		return true
	} else {
		return false
	}
}`