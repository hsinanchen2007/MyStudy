### 解题思路

* 利用slice实现队列的基本操作
* 使用q1,q2两个队列相互传值的方式实现stack的操作

```go
type MyStack struct {
	q1, q2 *MyQueue
}

type MyQueue struct {
	data []int
}

func (this *MyQueue) Push(x int) {
	this.data = append(this.data, x)
}

func (this *MyQueue) Pop() int {
	if len(this.data) > 0 {
		res := this.data[0]
		this.data = this.data[1:]
		return res
	}
	return 0
}

func (this *MyQueue) Size() int {
	return len(this.data)
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{
		q1: &MyQueue{},
		q2: &MyQueue{},
	}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	if this.q1.Size() > 0 {
		this.q1.Push(x)
	} else {
		this.q2.Push(x)
	}
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	if this.q1.Size() > 0 {
		for this.q1.Size() > 1 {
			this.q2.Push(this.q1.Pop())
		}
		return this.q1.Pop()
	} else if this.q2.Size() > 0 {
		for this.q2.Size() > 1 {
			this.q1.Push(this.q2.Pop())
		}
		return this.q2.Pop()
	}
	return 0
}

/** Get the top element. */
func (this *MyStack) Top() int {
	top := 0
	for this.q1.Size() > 0 {
		if this.q1.Size() == 1 {
			top = this.q1.Pop()
			this.q2.Push(top)
			return top
		} else {
			this.q2.Push(this.q1.Pop())
		}
	}

	for this.q2.Size() > 0 {
		if this.q2.Size() == 1 {
			top = this.q2.Pop()
			this.q1.Push(top)
			return top
		} else {
			this.q1.Push(this.q2.Pop())
		}
	}

	return 0
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.q1.Size() == 0 && this.q2.Size() == 0
}

```

