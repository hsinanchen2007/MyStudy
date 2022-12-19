```
type MyCircularQueue struct {
    Head int
    Tail int
    Val []int
    Max int
    Length int
}


/** Initialize your data structure here. Set the size of the queue to be k. */
func Constructor(k int) MyCircularQueue {
    return MyCircularQueue{
        Head : 0,
        Tail : 0,
        Val : make([]int, k),
        Max : k,
        Length : 0,
    }
}


/** Insert an element into the circular queue. Return true if the operation is successful. */
func (this *MyCircularQueue) EnQueue(value int) bool {
    if this.Length >= this.Max {
        return false
    }
    if this.Length > 0 {
        this.Tail  = (this.Tail + 1) % this.Max
    }
    this.Val[this.Tail] = value
    this.Length += 1
    return true
}


/** Delete an element from the circular queue. Return true if the operation is successful. */
func (this *MyCircularQueue) DeQueue() bool {
    if this.Length == 0 {
        return false
    }
    if this.Head == this.Tail {
        this.Tail = (this.Tail + 1) % this.Max
    }
    this.Head = (this.Head + 1) % this.Max
    this.Length -= 1
    return true
}


/** Get the front item from the queue. */
func (this *MyCircularQueue) Front() int {
    if this.Length == 0 {
        return -1
    }
    return this.Val[this.Head]
}


/** Get the last item from the queue. */
func (this *MyCircularQueue) Rear() int {
    if this.Length == 0 {
        return -1
    }
    return this.Val[this.Tail]
}


/** Checks whether the circular queue is empty or not. */
func (this *MyCircularQueue) IsEmpty() bool {
    if this.Length == 0 {
        return true
    }
    return false
}


/** Checks whether the circular queue is full or not. */
func (this *MyCircularQueue) IsFull() bool {
    if this.Length >= this.Max {
        return true
    }
    return false
}
```