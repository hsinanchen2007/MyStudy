1. 先将字符串入栈
2. 碰到右括号时，将入栈数据出栈，出栈中遇到一个左括号则反转这个字串
3. 然后将反转的字串在入栈
```
func reverseParentheses(s string) string {

	rightStack := []byte(s)
	l := len(rightStack)
	leftStack := []byte{}
	var b byte
	for i := 0; i < l; i++ {
		b = rightStack[i]
		if string(b) != ")" {
			leftStack = append(leftStack, b)
		} else {
			for j := len(leftStack) - 1; j >= 0; j-- {
				if string(leftStack[j]) == "(" {
					subByte := leftStack[j:]
					sl := len(subByte)
					// 存在一个左括号, 无子串
					if sl == 1 {
						leftStack = leftStack[:j]
					} else {
						reverseSub := subByte[1:sl]
						reverseStringByte(0, len(reverseSub) - 1, reverseSub)
						leftStack = leftStack[0:j]
						leftStack = append(leftStack, reverseSub...)
					}
					break
				}
			}

		}
	}

	return string(leftStack)

}

func reverseStringByte(start, end int, s []byte) {

	c := s[start]
	for start < end {
		s[start] = s[end]
		s[end] = c
		start++
		end--
		c = s[start]
	}
}
```
