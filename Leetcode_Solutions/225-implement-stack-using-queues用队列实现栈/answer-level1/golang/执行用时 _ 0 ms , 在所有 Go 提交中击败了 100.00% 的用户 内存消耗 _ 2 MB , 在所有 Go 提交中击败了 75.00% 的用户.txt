```
type MyStack struct {
	queue []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.queue = append(this.queue, x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	pop := 0
	if len(this.queue) != 0 {
		pop = this.queue[len(this.queue)-1]
		this.queue = this.queue[:len(this.queue)-1]
	}
	return pop
}

/** Get the top element. */
func (this *MyStack) Top() int {
	pop := 0
	if len(this.queue) != 0 {
		pop = this.queue[len(this.queue)-1]
	}
	return pop
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	if len(this.queue) == 0 {
		return true
	}
	return false
}
```
