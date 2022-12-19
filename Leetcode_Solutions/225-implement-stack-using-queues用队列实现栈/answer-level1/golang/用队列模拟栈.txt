### 解题思路
直接使用一个 slice 模拟 queue

### 代码

```golang
type MyStack struct {
    data []int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        data: []int{},
    }
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.data = append(this.data, x)
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {

    tmp := []int{}

    for len(this.data) > 1 {
        tmp = append(tmp, this.data[0])
        this.data = this.data[1:]
    }
    result := this.data[0]
    this.data = tmp
    return result
}


/** Get the top element. */
func (this *MyStack) Top() int {
    tmp := []int{}

    for len(this.data) > 1 {
        tmp = append(tmp, this.data[0])
        this.data = this.data[1:]
    }
    result := this.data[0]
    tmp = append(tmp, result)
    this.data = tmp
    return result
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    return len(this.data) == 0
}
```