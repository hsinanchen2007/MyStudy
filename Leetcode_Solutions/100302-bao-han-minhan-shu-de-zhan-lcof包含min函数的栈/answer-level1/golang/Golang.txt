### 代码

```golang
type MinStack struct {
    nums,mins []int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{[]int{},[]int{}}
}


func (this *MinStack) Push(x int)  {
    if len(this.nums)==0||x<=this.mins[len(this.mins)-1]{
        this.mins=append(this.mins,x)
    }
    this.nums=append(this.nums,x)
}


func (this *MinStack) Pop()  {
    if this.nums[len(this.nums)-1]==this.mins[len(this.mins)-1]{
        this.mins=this.mins[0:len(this.mins)-1]
    }
    this.nums=this.nums[0:len(this.nums)-1]
}


func (this *MinStack) Top() int {
    return this.nums[len(this.nums)-1]
}


func (this *MinStack) Min() int {
    return this.mins[len(this.mins)-1]
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Min();
 */
```