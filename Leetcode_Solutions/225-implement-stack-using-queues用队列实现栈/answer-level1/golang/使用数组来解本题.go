### 解题思路

1. 使用数组做为栈的数据结构
2. size当前保存了多少个有效数字，通过+-来调整下标，达成push和pop动作
3. cap数组的容量大小

### 代码

```golang
type MyStack struct {
    v []int
    size int
    cap int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        v: []int{},
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    if this.cap == 0 || this.cap == this.size {
        this.v = append(this.v,x)
        this.size++
        this.cap++
    }

    if this.size < this.cap {
        this.v[this.size] = x
        this.size++
    }
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    this.size--
    return this.v[this.size]
}


/** Get the top element. */
func (this *MyStack) Top() int {
    return this.v[this.size - 1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return this.size == 0
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