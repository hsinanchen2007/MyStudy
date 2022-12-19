利用队列实现栈。栈和队列唯一的不同只体现在出栈和出队列时，其余时刻都一样。

此题有两种解法，思路类似，都是将队列的最末尾元素作为栈顶元素出栈 


# 1. 使用一个队列

```
package golang

import "container/list"

type MyStack struct {
    Stack *list.List
}

/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        Stack: list.New(),
    }
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
    this.Stack.PushBack(x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    len := this.Stack.Len()
    // 将队列元素挨个出队列再插回队列，在出队列到最后一个的时候返回，实现出栈栈顶元素
    for i := 0; i < len; i++ {
        e := this.Stack.Remove(this.Stack.Front())
        if i == len-1 {
            return e.(int)
        }
        this.Stack.PushBack(e)
    }
    return -1
}

/** Get the top element. */
func (this *MyStack) Top() int {
    return this.Stack.Back().Value.(int)
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.Stack.Len() == 0
}

/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */

# 2. 两个队列 

两个队列同理， 