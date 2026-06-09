首先自定义一个队列：
```go
type Queue struct {
	data        []int
	front, tail int
}

func NewQueue() Queue {
	return Queue{
		data:  make([]int, 0),
		front: 0,
		tail:  0,
	}
}

func (q *Queue) Enqueue(x int) {
	q.data = append(q.data, x)
	q.tail++
}

func (q *Queue) Dequeue() int {
	ret := 0
	if q.front < q.tail {
		ret = q.data[q.front]
		q.front++
	}
	return ret
}

func (q *Queue) Size() int {
	return q.tail - q.front
}

func (q *Queue) Empty() bool {
	return q.front == q.tail
}
```

然后使用两个队列(a、b)来实现栈，其中**所有的操作都是在 a 上进行，b 是用于辅助的**：
```go
type MyStack struct {
	a, b Queue
}

func Constructor() MyStack {
	return MyStack{
		a: NewQueue(),
		b: NewQueue(),
	}
}

func (this *MyStack) Push(x int) {
	this.a.Enqueue(x)
}

func (this *MyStack) Pop() int {
    // 边界条件：当栈中仅有一个元素时直接出栈即可
	if this.a.Size() == 1{
		return this.a.Dequeue()
	}
    // 当栈中的元素不止一个时
    // 1. 先将 A 中除了队尾的元素(即栈顶元素)都出队并逐个入队到 B 中
    // 2. 然后缓存栈顶元素，在最后作为返回值返回
    // 3. 交换 A 和 B 的引用，
	for i := 0; i < this.a.Size(); i++ {
		this.b.Enqueue(this.a.Dequeue())
	}
	ret := this.a.Dequeue()
	this.a, this.b = this.b, this.a
	return ret
}

func (this *MyStack) Top() int {
	top := this.Pop()
	this.Push(top)
	return top
}

func (this *MyStack) Empty() bool {
	return this.a.Empty()
}
```