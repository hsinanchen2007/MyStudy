### 解题思路
go单调栈解法
### 代码

```golang
func largestRectangleArea(heights []int) int {
	var mSt Stack
	maxArea := 0
	heights = append([]int{0}, append(heights, 0)...)
	mSt.Push(0)
	//单调递减

	for i := 1; i < len(heights); i++ {
		if heights[mSt.Peek().(int)] <= heights[i] {
			mSt.Push(i)
		} else {
			for heights[mSt.Peek().(int)] > heights[i] {
				topIndex := mSt.Pop().(int)
				maxArea = max(maxArea, (i-mSt.Peek().(int)-1)*heights[topIndex])
			}
			mSt.Push(i)
		}
	}
	return maxArea
}
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

type (
	Stack struct {
		top    *node
		length int
	}
	node struct {
		value interface{}
		prev  *node
	}
)

// Create a new stack
func New() *Stack {
	return &Stack{nil, 0}
}

// Return the number of items in the stack
func (this *Stack) Len() int {
	return this.length
}

// View the top item on the stack
func (this *Stack) Peek() interface{} {
	if this.length == 0 {
		return nil
	}
	return this.top.value
}

// Pop the top item of the stack and return it
func (this *Stack) Pop() interface{} {
	if this.length == 0 {
		return nil
	}

	n := this.top
	this.top = n.prev
	this.length--
	return n.value
}

// Push a value onto the top of the stack
func (this *Stack) Push(value interface{}) {
	n := &node{value, this.top}
	this.top = n
	this.length++
}


```