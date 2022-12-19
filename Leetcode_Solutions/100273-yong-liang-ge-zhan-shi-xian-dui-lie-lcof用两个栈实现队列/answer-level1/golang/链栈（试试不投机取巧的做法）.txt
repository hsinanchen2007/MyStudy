### 解题思路
哈哈哈，时间复杂度不行，空间复杂度很优

### 代码

```golang
//双链栈实现队列

type StackNode struct {
	Val int
	Next *StackNode
}

type CQueue struct {
	aStack *StackNode
	dStack * StackNode
}

func InitialStack() *StackNode {
	headPointer := new(StackNode)
	headPointer.Val = 0
	headPointer.Next = nil

	return headPointer
}

func (this *StackNode) Push(value int) {
	p := new(StackNode)
	p.Val = value
	p.Next = this.Next
	this.Next = p
	this.Val++
}

func (this *StackNode) Pop() int {
	if this.Val == 0 {
		return -1
	}

	this.Val--
	result := this.Next.Val
	this.Next = this.Next.Next

	return result
}

func Constructor() CQueue {
	var queue CQueue
	queue.aStack = InitialStack()
	queue.dStack = InitialStack()

	return queue
}

func (this *CQueue) AppendTail(value int)  {
	this.aStack.Push(value)
}

func (this *CQueue) DeleteHead() int {
	aStackLen := this.aStack.Val
	for i:=0; i<aStackLen; i++ {
		this.dStack.Push(this.aStack.Pop())
	}

	result := this.dStack.Pop()

	for i:=0; i<aStackLen-1; i++ {
		this.aStack.Push(this.dStack.Pop())
	}

	return result
}
```