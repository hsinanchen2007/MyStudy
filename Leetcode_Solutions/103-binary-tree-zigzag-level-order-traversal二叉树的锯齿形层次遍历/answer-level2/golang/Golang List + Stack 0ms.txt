
    用一个stack实现一个level的反转

```

func zigzagLevelOrder(root *TreeNode) [][]int {
   ret := [][]int{}
	if root == nil {
		return ret
	}
	l := list.New()
	s := NewStack()
	l.PushBack(root)
	noReverse := true
	for l.Len() != 0 {
		n := l.Len()
		row := []int{}
		for e := l.Front(); n != 0; e = l.Front() {
			if noReverse == true {
				row = append(row, e.Value.(*TreeNode).Val)
			} else {
				s.Push(e.Value.(*TreeNode).Val)
			}
			if e.Value.(*TreeNode).Left != nil {
				l.PushBack(e.Value.(*TreeNode).Left)
			}
			if e.Value.(*TreeNode).Right != nil {
				l.PushBack(e.Value.(*TreeNode).Right)
			}
			l.Remove(e)
			n--
		}
		for s.Len() != 0 {
			row = append(row, s.Pop().(int))
		}
		ret = append(ret, row)
		noReverse = !noReverse
	}

	return ret
}

type stack struct {
	sl *list.List
}

func (s *stack) Pop() interface{} {
	return s.sl.Remove(s.sl.Back())
}
func (s *stack) Push(v interface{}) {
	s.sl.PushBack(v)
}

func (s *stack) Len() int {
	return s.sl.Len()
}

func NewStack() *stack {
	return &stack{sl: list.New()}
}
```
