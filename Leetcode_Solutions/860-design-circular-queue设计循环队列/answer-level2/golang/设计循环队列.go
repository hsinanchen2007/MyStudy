### 解题思路
循环数组

### 代码

```golang

//	622
type MyCircularQueue struct {
	data  []int
	front int
	rear  int
	cap   int
}

/** Initialize your data structure here. Set the size of the queue to be k. */
func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		data:  make([]int, k + 1),
		front: 0,
		rear:  0,
		cap:   k + 1,
	}
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
func (mcq *MyCircularQueue) EnQueue(value int) bool {
	if mcq.IsFull() {
		return false
	}
	mcq.data[mcq.rear] = value
	mcq.rear = (mcq.rear + 1) % mcq.cap
	return true
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
func (mcq *MyCircularQueue) DeQueue() bool {
	if mcq.IsEmpty() {
		return false
	}
	mcq.front = (mcq.front + 1) % mcq.cap
	return true
}

/** Get the front item from the queue. */
func (mcq *MyCircularQueue) Front() int {
	if !mcq.IsEmpty() {
		return mcq.data[mcq.front]
	}
	return -1
}

/** Get the last item from the queue. */
func (mcq *MyCircularQueue) Rear() int {
	if mcq.IsEmpty() {
		return -1
	}
	mod := (mcq.rear - 1) % mcq.cap
	if mod == -1 {
		mod = mcq.cap - 1
	}
	return mcq.data[mod]
}

/** Checks whether the circular queue is empty or not. */
func (mcq *MyCircularQueue) IsEmpty() bool {
	return mcq.front == mcq.rear
}

/** Checks whether the circular queue is full or not. */
func (mcq *MyCircularQueue) IsFull() bool {
	return (mcq.rear+1)%mcq.cap == mcq.front
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.EnQueue(value);
 * param_2 := obj.DeQueue();
 * param_3 := obj.Front();
 * param_4 := obj.Rear();
 * param_5 := obj.IsEmpty();
 * param_6 := obj.IsFull();
 */

```