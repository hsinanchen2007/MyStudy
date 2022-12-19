### 解题思路
入队列后循环出列直至新入队列的元素在队首

### 代码

```golang
type MyStack struct {
	queue []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{queue:make([]int, 0)}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
	this.queue=append(this.queue,x)
	for i:=0;i<len(this.queue)-1;i++{
		this.queue=append(this.queue[1:],this.queue[0]) // 循环出队列首并加入队尾
	}
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	out:=this.queue[0]
	this.queue=this.queue[1:]
	return out
}

/** Get the top element. */
func (this *MyStack) Top() int {
	return this.queue[0]
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return len(this.queue)==0
}

/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */
```