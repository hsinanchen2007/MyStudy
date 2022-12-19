### 解题思路

先定义一个栈的结构体，然后扫描字符串，如果是"[({"这三个就入栈，否则就和栈顶匹配。

最后还要检查栈是否为空。


### 代码

```golang
type stack struct {
	Length int
	Data   []int32
}

func (s *stack) Push(ch int32) {
	s.Data[s.Length] = ch
	s.Length++
}

func (s *stack) Pop() {
	s.Length--
}

func (s *stack) Top() int32 {
	return s.Data[s.Length-1]
}

func (s *stack) Empty() bool {
	return s.Length == 0
}

func isValid(s string) bool {
	strStack := stack{0, make([]int32, len(s))}
	for _, ch := range s {
		if ch == '(' || ch == '[' || ch == '{' {
			strStack.Push(ch)
		} else {
			if strStack.Empty() {
				return false
			}
			if ch == ')' && strStack.Top() != '(' {
					return false
			} else if ch == ']' && strStack.Top() != '[' {
					return false
			} else if ch == '}' && strStack.Top() != '{' {
					return false
			}
			strStack.Pop()
		}
	}
	return strStack.Empty()
}
```