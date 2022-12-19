### 解题思路
因为每次min都要取到目前的最小值
因为有pop的操作
那么就必须记录每次的最小值 考虑用辅助栈来记录最小值
每次push就将最小值压入栈，同步pop
那么每次辅助栈的栈顶就是min了

### 代码

```golang
type MinStack struct {
    spans []int
    helper []int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{spans:make([]int,0),helper:make([]int,0)}
}


func (this *MinStack) Push(x int)  {
    this.spans = append(this.spans,x)
    if this.Min()>x{
        this.helper = append(this.helper,x)
    }else{
        this.helper = append(this.helper,this.Min())
    }
}


func (this *MinStack) Pop()  {
    if len(this.spans) == 0{
        return
    }
    this.spans = this.spans[0:len(this.helper)-1]
    this.helper = this.helper[0:len(this.helper)-1]
}


func (this *MinStack) Top() int {
    if len(this.spans) == 0 {
        return 0
    }
    return this.spans[len(this.helper)-1]
}


func (this *MinStack) Min() int {
    if len(this.helper) == 0 {
        return 1<<31
    }
    return this.helper[len(this.helper)-1]
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