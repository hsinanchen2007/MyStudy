### 解题思路
使用单链表，不用考虑数组index，也无需变换数据元素所在位置的下标，
只需要注意链表长度不要超出题设给出的capacity就可以了
##
***代码块若有可更简化写法，还希望各路大神评论处留言，助我进步***
### 代码

```golang

type queueNode struct {
	val  int
	next *queueNode
}

type MyCircularQueue struct {
	header   *queueNode
	tail     *queueNode
	len      int
	capacity int
}

/** Initialize your data structure here. Set the size of the queue to be k. */
func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		header:   nil,
		tail:     nil,
		len:      0,
		capacity: k,
	}
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.len >= this.capacity {
		return false
	}


	if this.len == 0 {
		this.header = &queueNode{
			val:  value,
			next: nil,
		}
		this.tail = this.header
	} else {
		this.tail.next = &queueNode{
			val:  value,
			next: nil,
		}
		this.tail=this.tail.next
	}
	this.len++

	return true
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
func (this *MyCircularQueue) DeQueue() bool {
	if this.len == 0 {
		return false
	}
	this.header = this.header.next
	this.len--
	return true
}

/** Get the front item from the queue. */
func (this *MyCircularQueue) Front() int {
	if this.len == 0 {
		return -1
	}
	return this.header.val
}

/** Get the last item from the queue. */
func (this *MyCircularQueue) Rear() int {
	if this.len == 0 {
		return -1
	}
	return this.tail.val
}

/** Checks whether the circular queue is empty or not. */
func (this *MyCircularQueue) IsEmpty() bool {
	if this.len == 0 {
		return true
	}
	return false
}

/** Checks whether the circular queue is full or not. */
func (this *MyCircularQueue) IsFull() bool {
	if this.len == this.capacity {
		return true
	}
	return false
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