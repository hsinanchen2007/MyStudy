### 解题思路
使用两个栈，一个栈只接收新数据，另一个栈用来返回数据

### 代码

```golang
type MyQueue struct {
    in []int
    out []int
}


/** Initialize your data structure here. */
func Constructor() MyQueue {
    return MyQueue{}
}


/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int)  {
    this.in = append(this.in,x)
}


/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
    if len(this.out)==0{ //对于pop和peek操作，只要out栈为空，就将in栈数据搬移至out栈，否则直接返回out栈第一个元素
        for i:=len(this.in)-1; i>=0; i--{
            this.out = append(this.out, this.in[i])
        }
        this.in = nil
    }
    pop := this.out[len(this.out)-1]
    this.out = this.out[0:len(this.out)-1]
    return pop
}


/** Get the front element. */
func (this *MyQueue) Peek() int {
    if len(this.out)==0{
        for i:=len(this.in)-1; i>=0; i--{
            this.out = append(this.out, this.in[i])
        }
        this.in = nil
    }
    return this.out[len(this.out)-1]
}


/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
    if len(this.in)==0 && len(this.out)==0{
        return true
    }else{
        return false
    }
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