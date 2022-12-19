由于最小值仅和push和pop相关，那么记录子栈的最小值即可，因为一层层pop掉后，如果最小值出栈了，那么子栈的最小值将成为整个栈的最小值。

附上golang的题解：
```
type MinStack struct {
    top *Node
}

type Node struct {
    Val int
    SubMin int
    Next *Node
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{
        top: nil,
    }
}


func (this *MinStack) Push(x int)  {
    top := this.top
    if top == nil {
        c := Node{
            Val: x,
            SubMin: x,
            Next: nil,
        }
        this.top = &c
    } else {
        c := Node{
            Val: x,
            SubMin: top.SubMin,
            Next: top,
        }
        if c.SubMin > x {
            c.SubMin = x
        }
        this.top = &c
    }
}


func (this *MinStack) Pop()  {
    if this.top != nil {
        this.top = this.top.Next
    }
}


func (this *MinStack) Top() int {
    return this.top.Val
}


func (this *MinStack) GetMin() int {
    return this.top.SubMin
}
```
