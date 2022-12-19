### 代码

```golang
//import "container/list"

type MyStack struct {
	List *list.List
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	m := MyStack{}
	m.List = list.New()
	return m
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.List.PushFront(x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	val := this.List.Remove(this.List.Front())
	return val.(int)
}

/** Get the top element. */
func (this *MyStack) Top() int {
	return this.List.Front().Value.(int)
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.List.Len() == 0
}
```