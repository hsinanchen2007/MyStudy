### 解题思路
Pop操作是O(n)的时间复杂度，空间复杂度O(1)

### 代码

```golang
type MinStack struct {
    nums []int
    min int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{[]int{},0}
}


func (this *MinStack) Push(x int)  {
    if len(this.nums)==0{
        this.min=x
    }else{
        if x<this.min{
            this.min=x
        }
    }
    this.nums=append(this.nums,x)
}


func (this *MinStack) Pop()  {
    t:=this.nums[len(this.nums)-1]
    this.nums=this.nums[0:len(this.nums)-1]
    if t==this.min{
        if len(this.nums)>0{
            this.min=this.nums[0]
            for _,v:=range this.nums{
                if v<this.min{
                    this.min=v
                }
            }
        }
    }
}


func (this *MinStack) Top() int {
    return this.nums[len(this.nums)-1]
}


func (this *MinStack) Min() int {
    return this.min
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