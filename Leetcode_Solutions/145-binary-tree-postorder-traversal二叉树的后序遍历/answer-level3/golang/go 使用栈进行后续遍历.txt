### 解题思路
go 使用栈进行后续遍历
### 代码

```golang

func postorderTraversal(root *TreeNode) []int {
	var st Stack
	cur := root
	ret := make([]int, 0, 0)
	lastVisit := root
	for cur != nil || st.Len() != 0 {
		for cur != nil {
			st.Push(cur)
			cur = cur.Left
		}

		cur = st.Peek().(*TreeNode)

		if cur.Right == nil || cur.Right == lastVisit {
			ret = append(ret, cur.Val)
			lastVisit = st.Pop().(*TreeNode)
			cur = nil
		} else {
			cur = cur.Right
		}

	}
	return ret
}

type (
	Stack struct {
		top *node
		length int
	}
	node struct {
		value interface{}
		prev *node
	}
)
// Create a new stack
func New() *Stack {
	return &Stack{nil,0}
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
	n := &node{value,this.top}
	this.top = n
	this.length++
}
```