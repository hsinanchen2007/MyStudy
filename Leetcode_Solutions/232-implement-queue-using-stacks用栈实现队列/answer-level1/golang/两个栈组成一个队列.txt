```
type MyQueue struct {
	stackPush []int
	stackPop []int
}


/** Initialize your data structure here. */
func Constructor() MyQueue {
	return  MyQueue{}
}


// 把全部数据压入stackPop栈内
func (this *MyQueue) pushToPop() {
	if len(this.stackPop) <= 0 {
		for _, val := range this.stackPush {
			this.stackPop =  append(this.stackPop, val)
		}
	// 清空stackPush
	this.stackPush = nil
	}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
	this.stackPush = append(this.stackPush, x)
	this.pushToPop()
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	if (len(this.stackPop) <= 0 && len(this.stackPush)<=0) {
		return 0
	}
	this.pushToPop()
	ret := this.stackPop[0]
	this.stackPop = this.stackPop[1:]
	return ret
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
	if (len(this.stackPop) <= 0 && len(this.stackPush)<=0) {
		return 0
	}
	this.pushToPop()
		return this.stackPop[0]
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return (len(this.stackPop) <= 0 && len(this.stackPush)<=0) 
}
```
