### 解题思路
此处撰写解题思路

### 代码

```golang
type MyQueue struct {
	in  []int
	out []int
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.in = append(this.in, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	this.flip()
	if this.Empty() {
		return 0
	}
	top := this.out[len(this.out)-1]
	this.out = this.out[:len(this.out)-1]
	return top
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	this.flip()
	top := 0
	if len(this.out) > 0 {
		top = this.out[len(this.out)-1]
	}
	return top
}

func (this *MyQueue) flip() {
	if len(this.out) != 0 {
		return
	}
	for i := len(this.in) - 1; i >= 0; i-- {
		this.out = append(this.out, this.in[i]) //将入栈的数据，反过来放到出栈
		this.in = this.in[:i]
	}
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	if len(this.in) > 0 || len(this.out) > 0 {
		return false
	}
	return true
}
```