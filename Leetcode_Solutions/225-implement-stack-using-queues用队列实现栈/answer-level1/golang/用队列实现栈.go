### 解题思路
使用两个切片

### 代码

```golang

type MyStack struct {
	slice1 []int
	slice2 []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{
		slice1: make([]int, 0),
		slice2: make([]int, 0),
	}
}

/** Push element x onto stack. */
func (s *MyStack) Push(x int) {
	if len(s.slice1) > 0 {
		s.slice1 = append(s.slice1, x)
	}else {
		s.slice2 = append(s.slice2, x)
	}
}

/** Removes the element on top of the stack and returns that element. */
func (s *MyStack) Pop() int {
	var top int
	if len(s.slice1) > 0 {
		for len(s.slice1) > 1{
			s.slice2 = append(s.slice2, s.slice1[0])
			s.slice1 = s.slice1[1:]
		}
		top = s.slice1[0]
		s.slice1 = s.slice1[1:]
	}else {
		for len(s.slice2) > 1{
			s.slice1 = append(s.slice1, s.slice2[0])
			s.slice2 = s.slice2[1:]
		}
		top = s.slice2[0]
		s.slice2 = s.slice2[1:]
	}
	return top
}

/** Get the top element. */
func (s *MyStack) Top() int {
	var top int
	if len(s.slice1) > 0 {
		for len(s.slice1) > 1{
			s.slice2 = append(s.slice2, s.slice1[0])
			s.slice1 = s.slice1[1:]
		}
		top = s.slice1[0]
		s.slice2 = append(s.slice2, s.slice1[0])
		s.slice1 = s.slice1[1:]
	}else {
		for len(s.slice2) > 1{
			s.slice1 = append(s.slice1, s.slice2[0])
			s.slice2 = s.slice2[1:]
		}
		top = s.slice2[0]
		s.slice1 = append(s.slice1, s.slice2[0])
		s.slice2 = s.slice2[1:]
	}
	return top
}

/** Returns whether the stack is empty. */
func (s *MyStack) Empty() bool {
	return len(s.slice1) == 0 && len(s.slice2) == 0
}

```