### 解题思路
此处撰写解题思路

### 代码

```golang
type MyQueue struct {
    value []int
}


/** Initialize your data structure here. */
func Constructor() MyQueue {
    return MyQueue{value:[]int{}}   //静态显示初始化为空
}


/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.value=append(this.value,x)
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    result:= this.value[0]
    this.value=this.value[1:len(this.value)]
    return result 
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
    return this.value[0]
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    fmt.Println(len(this.value))
    return len(this.value)==0
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