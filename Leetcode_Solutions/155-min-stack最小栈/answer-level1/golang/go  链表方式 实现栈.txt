### 解题思路
此处撰写解题思路

### 代码

```golang
type MinStack struct {
    Min  int
    Val  int
    Next *MinStack
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{}
}


func (this *MinStack) Push(x int)  {
    temp := &MinStack{x, x, nil}
    if this.Next == nil {
        this.Next = temp
    }else if x > this.Next.Min {
        temp.Min = this.Next.Min
        temp.Next = this.Next
        this.Next = temp
    }else {
        temp.Next = this.Next
        this.Next = temp
    }
}


func (this *MinStack) Pop()  {
    if this.Next != nil {
        this.Next = this.Next.Next
    }
   
}


func (this *MinStack) Top() int {
    if this.Next != nil {
        return this.Next.Val
    }
    return 0
}


func (this *MinStack) GetMin() int {
     if this.Next != nil {
        return this.Next.Min
    }
    return (1<<31) -1
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
```