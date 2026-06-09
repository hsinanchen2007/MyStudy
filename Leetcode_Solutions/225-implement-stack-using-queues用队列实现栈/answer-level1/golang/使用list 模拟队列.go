### 解题思路
用列表list 来模拟队列，这里有个取巧的地方就是使用了双向队列的Back 方法获取了尾部元素，
否则需要再用一个队列暂存之前的元素，获取Top/Pop 

### 代码

```golang
import "container/list"

type MyStack struct {
    l    *list.List
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    l := list.New()
    return MyStack{l}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.l.PushBack(x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    e := this.l.Back()
    if e!= nil {
        this.l.Remove(e)
        return e.Value.(int)
    }
    return -1
}


/** Get the top element. */
func (this *MyStack) Top() int {
    e := this.l.Back()
    if e !=nil {
        return e.Value.(int)
    }
    return -1
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.l.Len() == 0
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