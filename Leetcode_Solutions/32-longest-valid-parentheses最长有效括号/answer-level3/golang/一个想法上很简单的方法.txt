把字符串从左到右的字符逐个压入栈中, 

1. 如果准备压入的是`)`, 检查栈顶是否是`(`, 如果是, 就弹出`(`, 并扔掉这个`)`
2. 其他情况, 压入字符

到最后, 看栈中剩下的部分, 他们中间缺失的就是局部最长的子串, 想办法知道剩下部分的字符在原来字符串中的序号, 就只需要遍历一遍求相邻的字符序号之差, 就能求出最长符合要求子串长度

```go
func longestValidParentheses(s string) int {
	record := make([]int, 0)
	stack := make([]string, 0)
	for i, c := range s {
		if string(c) == ")" && len(record) != 0 && stack[len(stack)-1] == "(" {
			record = record[0:len(record)-1]
			stack = stack[0:len(stack)-1]
		} else {
			record = append(record, i)
			stack = append(stack, string(c))
		}
	}

	record = append(record, len(s))
	left := -1
	maxLength := 0
	for i:=0;i<len(record);i++ {
		if (record[i] - left - 1) > maxLength {
			maxLength = record[i] - left - 1
		}
		left = record[i]
	}

	return maxLength
}
```