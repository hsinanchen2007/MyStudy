type MyQueue struct {
    Input []int
    Output []int
}


/** Initialize your data structure here. */
func Constructor() MyQueue {
    return MyQueue{}
}


/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.Input = append(this.Input, x)
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    if len(this.Output) > 0 {
        val := this.Output[len(this.Output)-1]
        this.Output = this.Output[:len(this.Output)-1]
        return val
    }
    for i := len(this.Input)-1; i > 0; i-- {
        this.Output = append(this.Output, this.Input[i])
    }
    val := this.Input[0]
    this.Input = this.Input[:0]
    return val
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
    if len(this.Output) > 0 {
        return this.Output[len(this.Output)-1]
    } 
    return this.Input[0]
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    return len(this.Input)==0 && len(this.Output) == 0
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */