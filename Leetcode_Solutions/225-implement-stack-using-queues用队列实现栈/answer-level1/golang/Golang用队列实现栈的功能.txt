1、go中没有实现队列的功能，需要自己实现一个队列的功能

```go
type Item interface {
}

// 队列 先进先出
type Queue struct {
	list []Item
}

type QueueInterface interface {
	// New() *Queue
	Enqueue(item Item) int // 入队
	Dequeue() (item *Item) // 出队
	IsEmpty() bool
	Size() int
}

func NewQueue() *Queue {
	queue := &Queue{
		list: make([]Item, 0),
	}

	return queue
}

func (q *Queue) Enqueue(item Item) int {
	q.list = append(q.list, item)

	return q.Size()
}

func (q *Queue) Dequeue() (item *Item) {
	if q.Size() <= 0 {

		return nil
	}
	item = &q.list[0]
	q.list = q.list[1:]

	return
}

func (q *Queue) IsEmpty() bool {
	return q.Size() == 0
}

func (q *Queue) Size() int {
	return len(q.list)
}
```

2、 初始化队列
这里选择用一个队列来实现
```go
func Constructor() MyStack {
	queue := NewQueue()

	stack := MyStack{
		queue: queue,
	}

	return stack
}
```

3、 入栈
插入队列末尾，这里我们将元素的排列顺序和队列相同

```go
func (this *MyStack) Push(x int) {
	this.queue.Enqueue(x)
}
```
时间复杂度: **O(1)**

4、出栈
需要反向从队列中取数据
- 取出队列头**size-1**个元素放入队列末尾
- 再从队尾取出一个元素，即为需要出栈的元素
```go
func (this *MyStack) Pop() int {
	size := this.queue.Size()

	for i := 0; i < size; i++ {
		x := interface{}(*this.queue.Dequeue()).(int)
		if i == size-1 {
			return x
		}

		this.queue.Enqueue(x)
	}

	return 0
}
```
时间复杂度: **O(n)**

- 完整代码
```go
type MyStack struct {
	queue *Queue
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	queue := NewQueue()

	stack := MyStack{
		queue: queue,
	}

	return stack
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.queue.Enqueue(x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	size := this.queue.Size()

	for i := 0; i < size; i++ {
		x := interface{}(*this.queue.Dequeue()).(int)
		if i == size-1 {
			return x
		}

		this.queue.Enqueue(x)
	}

	return 0
}

/** Get the top element. */
func (this *MyStack) Top() int {
	size := this.queue.Size()

	var (
		x int
	)
	for i := 0; i < size; i++ {
		x = interface{}(*this.queue.Dequeue()).(int)
		this.queue.Enqueue(x)
	}

	return x
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.queue.IsEmpty()
}
```


