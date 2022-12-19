
采用两个栈，一个栈用来存放原始元素，另一个栈专门用来存放最小值

```
type MinStack struct {
    elems []int 
    mins []int 
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{
        elems: make([]int, 0),
        mins: make([]int, 0),
    }
}


func (this *MinStack) Push(x int)  {
    this.elems = append(this.elems, x)
    if len(this.mins) == 0 {
        this.mins = append(this.mins, x)
    } else {
        if this.mins[len(this.mins) - 1] >= x {
            this.mins = append(this.mins, x)
        }
    }
}


func (this *MinStack) Pop()  {
    elem := this.elems[len(this.elems) - 1]
    this.elems = this.elems[:len(this.elems)-1]
    if elem == this.mins[len(this.mins)-1] {
        this.mins = this.mins[:len(this.mins)-1]
    }
}


func (this *MinStack) Top() int {
    return this.elems[len(this.elems)-1]
}


func (this *MinStack) GetMin() int {
    return this.mins[len(this.mins)-1]
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