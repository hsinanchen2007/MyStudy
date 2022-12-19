### 解题思路

简单地说，我们可以使用双队列（当然也可以用双端队列实现），利用队列的FIFO特点。比如：
入栈时我们总是将入栈的元素放到一个队列中即可
出栈时我们可以将存放栈元素的队列，逐个入队到另一个队列中，直至剩下一个用于返回，其思想就是通过出队操作，将队尾的元素移动到队首，然后交换两个队列的变量的指向即可（而不是从新入队和出队）

**双队列**：设两个队列pushQueue, popQueue。pushQueue负责接收入栈的元素，popQueue负责出栈。
**入栈实现**：入栈很简单，就是调用pushQueue.Enqueue()方法即可
**出栈实现**：对于出栈操作，我们知道队列是FIFO，因此我们需要将pushQueue中的元素Enqueue到popQueue中，并且留下一个元素用于Dequeue()返回，然后交换二者的引用即可
**获取栈顶元素**：这个跟出栈大致相同，唯一不同的是在pushQueue留下的那个元素不仅作为返回值，而且会首先Enqueue()到popQueue中，然后交换两个队列的引用

### 代码

```golang
type MyStack struct {
    pushQueue, popQueue *Queue
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        pushQueue: newQueue(),
        popQueue: newQueue(),
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.pushQueue.enqueue(x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    for this.pushQueue.length > 1 {
        this.popQueue.enqueue(this.pushQueue.dequeue())
    }
    value := this.pushQueue.dequeue()
    this.pushQueue, this.popQueue = this.popQueue, this.pushQueue

    return value
}


/** Get the top element. */
func (this *MyStack) Top() int {
    for this.pushQueue.length > 1 {
        this.popQueue.enqueue(this.pushQueue.dequeue())
    }
    value := this.pushQueue.dequeue()
    this.pushQueue, this.popQueue = this.popQueue, this.pushQueue
    this.pushQueue.enqueue(value)

    return value
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.pushQueue.isEmpty()
}

type Queue struct {
    data []int
    length int
}

func newQueue() *Queue {
    return &Queue{
        data: make([]int, 0),
    }
}

func (queue *Queue) isEmpty() bool {
    return queue.length == 0
}

func (queue *Queue) enqueue(x int) {
    queue.data = append(queue.data, x)
    queue.length++
}

func (queue *Queue) dequeue() int {
    value := queue.data[0]
    queue.data = queue.data[1:]
    queue.length--

    return value
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