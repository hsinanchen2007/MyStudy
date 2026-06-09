自己构造栈来实现：

参考学习

```go
// 栈的结构体
type ArrayStack struct {
	items []int // 栈的元素-数据
	top   int   // 栈顶指针
}

// 初始化栈-新建栈
func NewArrayStack() *ArrayStack {
	return &ArrayStack{
		items: make([]int, 0, 32),
		top:   -1,
	}
}

// 判断栈是否为空
func (s *ArrayStack) IsEmpty() bool {
	if s.top < 0 {
		return true
	}
	return false
}

// 入栈操作
func (s *ArrayStack) Push(item int) {
	if s.top < 0 {
		// 如果栈空
		s.top = 0
	} else {
		// 栈的元素个数加一
		s.top++
	}

	if s.top > len(s.items)-1 {
		// slice扩容并追加数据
		s.items = append(s.items, item)
	} else {
		// 将item放到下标为top的位置
		s.items[s.top] = item
	}
}

// 出栈操作
func (s *ArrayStack) Pop() int {
	// 栈为空，则直接返回nil
	if s.IsEmpty() {
		return 0
	}
	// 返回下标为top的数组元素，并且栈中元素个数top减一
	tmp := s.items[s.top]
	s.top--
	return tmp
}

// 查看栈顶元素方法
func (s *ArrayStack) Top() int {
	if s.IsEmpty() {
		return 0
	}
	return s.items[s.top]
}

func find132pattern(nums []int) bool {
	n := len(nums)
	last := -1 << 31         // 132中的2
	stack := NewArrayStack() // 用来存储132中的3
	if n < 3 {
		return false
	}
	for i := n - 1; i >= 0; i-- {
		if nums[i] < last { // 若出现132中的1则返回正确值
			return true
		}
		// 若当前值大于或等于2则更新2(2为栈中小于当前值的最大元素)
		for !stack.IsEmpty() && stack.Top() < nums[i] {
			last = stack.Pop()
		}
		// 将当前值压入栈中
		stack.Push(nums[i])
	}
	return false
}
```