### 解题思路
用队列实现栈，本质上就是用队列先进先出的特点来实现栈后进先出的特点，这就意味着，一个队列时不行的，至少需要两个队列才能模拟栈的情况。
基本思路：
1. 压栈时存入主队列
2. 出栈时除了主队列最后一个元素，其余入队到help队列，直到最后一个元素出栈
3. 然后把help队列的整体全部重新赋给主队列

### 代码

```golang
/* 
基本思路，压栈时存入主队列
出栈时除了主队列最后一个元素，其余入队到help队列，直到最后一个元素出栈
然后把help队列的整体全部重新赋给主队列
*/
type MyStack struct {
    main []int
    help []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.main = append(this.main, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    for len(this.main) > 1 {
        item := this.main[0]
        this.main = this.main[1:]
        this.help = append(this.help, item)
    }
    res := this.main[0]
    this.main = this.main[1:]
    this.main, this.help = this.help, this.main
    return res
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.main[len(this.main) - 1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if len(this.main) == 0 {
        return true
    } else {
        return false
    }
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