### 解题思路
参考了大神代码，更喜欢结构声明中只有一个队列的方式，以上

### 代码

```golang
type MyStack struct {
    queue []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    var mystack MyStack
    return mystack
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    var i int
    var queue2 []int
    var length int
    queue2 = append(queue2, x)
    length = len(this.queue)
    if length != 0 {
        for i = 0; i < length; i++ {
            queue2 = append(queue2, this.queue[i])
        }
    }
    this.queue = queue2
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    var i int
    var top int
    var queue2 []int
    var length int
    length = len(this.queue)
    if length != 0 {
        for i = 1; i < length; i++ {
            queue2 = append(queue2, this.queue[i])
        }
    }
    top = this.queue[0]
    this.queue = queue2

    return top
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.queue[0]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.queue) == 0
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