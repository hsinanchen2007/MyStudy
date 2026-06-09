### 解题思路
首先明确队列和栈的特点：
- 队列：First in, first out
- 栈：First in, last out

这道题的关键其实是想到 “用两个队列来实现栈”。初始化两个队列 q1 和 q2。
- （1）当执行入栈操作时，就将元素添加到队列 q1
- （2）当执行出栈操作时，就将 q1 中的元素陆续搬到 q2，当 q1 中只剩下一个时，改元素就是所谓的 “栈顶元素”。注意：该元素不要进入队列 q2。
- （3）当执行获取栈顶元素时，操作类似 （2），只不过没有删除元素的操作。

我采用 Go 来解题。当然可以用 slice 来做，但这与违背了题目本来的考点，所以不采用 slice。最终决定用 container/list 来模拟队列，因为 Go 内置的库函数其实是没有 queue 的。代码如下，供参考：

```go
import "container/list"

type MyStack struct {
    q1 *list.List
    q2 *list.List
}

/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        q1: list.New(),
        q2: list.New(),
    }
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.q1.PushBack(x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    for this.q1.Len() > 1 {
        ele := this.q1.Front()
        fmt.Printf("ele value is %v\n", ele.Value)
        this.q2.PushBack(ele.Value)
        this.q1.Remove(ele)
    }
    res := this.q1.Front()
    this.q1.Remove(res)

    this.q1 = this.q2
    this.q2 = list.New()

    return res.Value.(int)
}

/** Get the top element. */
func (this *MyStack) Top() int {
    ele := this.Pop()
    this.q1.PushBack(ele)
    return ele
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.q1.Len() == 0
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