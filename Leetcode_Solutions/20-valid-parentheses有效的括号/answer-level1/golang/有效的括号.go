堆栈思路 go 版本。

```go [go]

type Stack struct{
	sli []string
} 

func (s *Stack) Push(ele string) {
	s.sli =append(s.sli,ele)
}

func (s *Stack) Pop() string {
	if len(s.sli) == 0 {
		return ""
	}

	ele := s.sli[len(s.sli)-1]
	s.sli = s.sli[:len(s.sli)-1]

	return ele
}

var m = map[string]string{
	")":"(",
	"]":"[",
	"}":"{",
}

func isValid(s string) bool {
	if s =="" {
		return true
	}
	var stack = new(Stack)

	for _,r := range s {
		 v := m[string(r)]
		 if v == "" {
			stack.Push(string(r))
			continue
		 }

		 p := stack.Pop()
		 if p == "" || p != v {
			 return false
		 }
		}
		 return len(stack.sli) == 0
}
```