```

func backspaceCompare(S string, T string) bool {
	sStack := genStack(S)
	tStack := genStack(T)

	for {
		s := sStack.Pop()
		t := tStack.Pop()

		if s == nil && t == nil {
			return true
		}

		if s != nil {
			if t == nil {
				return false
			}
		}

		if t != nil {
			if s == nil {
				return false
			}
		}

		if *s != *t {
			return false
		}

	}

}

func genStack(s string) *Stack {
	stack := InitStack()
	for _, ss := range s {
		if ss == '#' {
			stack.Pop()
		} else {
			stack.Push(int(ss))
		}
	}
	return stack
}


type Stack struct {
	Vals []*int
}

func InitStack() *Stack {
	return &Stack{}
}

func (s *Stack) Pop() *int {
	if len(s.Vals) == 0 {
		return nil
	}
	end := len(s.Vals) - 1
	result := s.Vals[end]
	s.Vals = s.Vals[:end]

	return result
}

func (s *Stack) Push(val int) {
	s.Vals = append(s.Vals, &val)
}

```