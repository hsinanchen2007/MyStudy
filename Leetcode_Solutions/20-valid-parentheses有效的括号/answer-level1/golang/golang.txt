```
func isValid(s string) bool {
    stack := InitStack()
	for _, c := range s {
		if c == 123 || c == 91 || c == 40 {
			stack.Push(int(c))
		}
		if c == 125 || c == 93 || c == 41 {
			p := stack.Pop()
            if p == nil {
				return false
			}
			if !((c == 125 && *p == 123) || (c == 93 && *p == 91) || (c == 41 && *p == 40)) {
				return false
			}
		}
	}

	if stack.Pop() == nil {
		return true
	}

	return false
}


type Stack struct {
	vals []*int
}

func InitStack() *Stack {
	return &Stack{}
}

func (s *Stack) Pop() *int {
	if len(s.vals) == 0 {
		return nil
	}
	end := len(s.vals) - 1
	result := s.vals[end]
	s.vals = s.vals[:end]

	return result
}

func (s *Stack) Push(val int) {
	s.vals = append(s.vals, &val)
}
```