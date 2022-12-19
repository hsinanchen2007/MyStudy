### 解题思路
Golang没有自带队列，用两个切片代替，切片的使用方法跟队列有很大区别，因此并没有严格地当成队列使用。
实际用一个切片就足够，但队列必须是两个，所以使用了两个切片

### 代码

```golang
type MyStack struct {
    queue1 []int
    queue2 []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        queue1: make([]int, 0),
        queue2: make([]int, 0),
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    if len(this.queue2) > 0 {
        for i := len(this.queue2)-1; i >= 0; i-- {
            this.queue1 = append(this.queue1, this.queue2[i])
        }
        this.queue2 = []int{}
    }
    this.queue1 = append(this.queue1, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    if len(this.queue2) > 0 {
        for i := len(this.queue2)-1; i >= 0; i-- {
            this.queue1 = append(this.queue1, this.queue2[i])
        }
        this.queue2 = []int{}
    }

    value := this.queue1[len(this.queue1)-1]
    this.queue1 = this.queue1[:len(this.queue1)-1]
    return value
}


/** Get the top element. */
func (this *MyStack) Top() int {
    if len(this.queue2) > 0 {
        return this.queue1[0]
    } else {
        return this.queue1[len(this.queue1)-1]
    }
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.queue1) == 0 && len(this.queue2) == 0
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