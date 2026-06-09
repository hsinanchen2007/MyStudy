因为题目要求了：你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。

所以用数组什么的是不符合要求的，因为 nums[len(nums)-1] 属于 pop from back。

```
import "container/list"

type MyStack struct {
	l1 *list.List
	l2 *list.List
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{
		l1: list.New(),
		l2: list.New(),
	}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	if this.l1.Len() == 0 {
		this.l2.PushBack(x)
	} else {
		this.l1.PushBack(x)
	}
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	var from, to *list.List
	if this.l1.Len() == 0 {
		from = this.l2
		to = this.l1
	} else {
		from = this.l1
		to = this.l2
	}

	for from.Len() != 1 {
		to.PushBack(from.Remove(from.Front()))
	}
	return from.Remove(from.Front()).(int)
}

/** Get the top element. */
func (this *MyStack) Top() int {
	var from, to *list.List
	if this.l1.Len() != 0 {
		from = this.l1
		to = this.l2
	} else {
		from = this.l2
		to = this.l1
	}

	for from.Len() != 1 {
		to.PushBack(from.Remove(from.Front()))
	}
	rtn := from.Remove(from.Front())
	to.PushBack(rtn)
	return rtn.(int)
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.l1.Len() == 0 && this.l2.Len() == 0
}
```
