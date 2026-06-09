### 解题思路
我自己在本地用了两种方法实现的，运行结果都是一样的，结果提交上来，链表法是对的，数组法就出错。思路大家都知道，问题为什么不能描述的详细一点。

### 代码

```golang
type MinStack struct {
    Val int
    Min int
    Next *MinStack
}
 
 
/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{0, 0, nil}
}
 
 
func (this *MinStack) Push(x int)  {
    Min := x
    if this.Next != nil {
        Min = int(math.Min(float64(x), float64(this.Next.Min)))
    }
    temp := &MinStack{Val:x, Min:Min, Next:this.Next}
    this.Next = temp
}
 
 
func (this *MinStack) Pop()  {
    if this.Next == nil {
        return
    }
    this.Next = this.Next.Next
}
 
 
func (this *MinStack) Top() int {
    if this.Next == nil {
        return 0
    }
    return this.Next.Val
}
 
 
func (this *MinStack) GetMin() int {
    if this.Next == nil {
        return 0
    }
    return this.Next.Min
}
```