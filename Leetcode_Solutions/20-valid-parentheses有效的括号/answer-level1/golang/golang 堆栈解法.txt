```go
func isValid(s string) bool {
    stack := NewStringStack()
    matchArr := map[string]string{
		"(": ")",
		"[": "]",
		"{": "}",
	}

	for _, v := range s {
		value := string(v)
		if _, isLeft := matchArr[value]; isLeft {
			stack.Push(value)
		} else if matchArr[stack.Pop()] != value {
			return false
		}
	}
	return stack.IsEmpty()   
}

// Stack 是用于存放 int 的 栈
type StringStack struct {
	nums []string
}

// NewStack 返回 *kit.Stack
func NewStringStack() *StringStack {
	return &StringStack{nums: []string{}}
}

// Push 把 n 放入 栈
func (s *StringStack) Push(n string) {
	s.nums = append(s.nums, n)
}

// Pop 从 s 中取出最后放入 栈 的值
func (s *StringStack) Pop() string {
	if s.IsEmpty() {
		return ""
	}
	res := s.nums[len(s.nums)-1]
	s.nums = s.nums[:len(s.nums)-1]
	return res
}

// Len 返回 s 的长度
func (s *StringStack) Len() int {
	return len(s.nums)
}

// IsEmpty 反馈 s 是否为空
func (s *StringStack) IsEmpty() bool {
	return s.Len() == 0
}
```
