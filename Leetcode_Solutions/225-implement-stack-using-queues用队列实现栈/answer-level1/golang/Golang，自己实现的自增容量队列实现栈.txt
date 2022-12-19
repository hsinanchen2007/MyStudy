### 解题思路
整体思路各路大牛都说的七七八八了，本篇Golang的分享一个用自己的队列实现栈。
思路：双队列，插入O(n)，弹出O(1)
receive队列：或者说是一个临时队列，保持常空，主要是用作插入时倒腾队列使用。
pop队列：用于输出栈元素的队列，每次插入时都会将内部元素全部pop至receive，然后swap这两个队列的指针，以达到后入先出的目的。

队列的实现：数组+双指针循环队列，会自动判断full并且扩容（初始128，每次扩容1倍）
扩容原理：检查head是否指向头部，如果不是，将head到结尾的元素和开头到tail的元素重新整理到从头部开始后，向尾部填充一个自身相等容量的空数组。
队列在某些情况下插入（扩容时）会发生O(n)的操作，其余情况均为常数级。

### 代码

```golang
type MyQueue struct {
	data   []int
	cap    int
	head   int
	tail   int
	Length int
}

func QueueConstructor() MyQueue {
	return MyQueue{
		make([]int, 128),
		128,
		-1,
		-1,
		0,
	}
}

func (q *MyQueue) Empty() bool {
	return q.head == -1
}

func (q *MyQueue) Full() bool {
	return (q.tail+1)%q.cap == q.head
}

func (q *MyQueue) Push(x int) {
	if q.Empty() {
		q.head = 0
		q.tail = -1
	} else if q.Full() {
		if q.head != 0 {
			left := q.data[q.head:]
			right := q.data[:q.head]
			q.data = append(left, right...)
		}
		moreCap := make([]int, q.cap)
		q.data = append(q.data, moreCap...)
		q.head = 0
		q.tail = q.cap - 1
		q.cap = q.cap << 1
	}
	q.tail = (q.tail + 1) % q.cap
	q.data[q.tail] = x
	q.Length++

}

func (q *MyQueue) Pop() int {
	if !q.Empty() {
		ret := q.data[q.head]
		q.head = (q.head + 1) % q.cap
		q.Length--
		if q.Length == 0 {
			q.head = -1
			q.tail = -1
		}
		return ret
	}
	return 0
}

func (q *MyQueue) Peek() int {
	if !q.Empty() {
		return q.data[q.head]
	}
	return 0
}

func (q *MyQueue) Print() {
	fmt.Println(q.data)
}

type MyStack struct {
	receiveQueue MyQueue
	popQueue     MyQueue
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{
		QueueConstructor(),
		QueueConstructor(),
	}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.receiveQueue.Push(x)
	for !this.popQueue.Empty() {
		this.receiveQueue.Push(this.popQueue.Pop())
	}
	tmp := this.receiveQueue
	this.receiveQueue = this.popQueue
	this.popQueue = tmp
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	return this.popQueue.Pop()
}

/** Get the top element. */
func (this *MyStack) Top() int {
	return this.popQueue.Peek()
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.popQueue.Empty()
}
```