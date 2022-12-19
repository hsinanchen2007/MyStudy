```
type MyQueue struct {
    data []int
}


/** Initialize your data structure here. */
func Constructor() MyQueue {
    return MyQueue{}
}


/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.data = append(this.data,x)
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    front := this.data[0]
    this.data = this.data[1:]
    return front
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
    return this.data[0]
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    if len(this.data) == 0{
        return true
    }
    return false
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
```
