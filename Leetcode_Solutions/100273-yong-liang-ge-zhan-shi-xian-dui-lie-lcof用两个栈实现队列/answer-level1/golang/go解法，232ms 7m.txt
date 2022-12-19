思路：使用切片作为数据承载，append作为末尾入队，出队进行切片切割，推出头数据。
```
type CQueue struct {
    Var []int
}


func Constructor() CQueue {
    return CQueue{}
}


func (this *CQueue) AppendTail(value int)  {
    this.Var = append(this.Var,value)

}


func (this *CQueue) DeleteHead() int {
    if len(this.Var) == 0{
        return -1
    }
    a := this.Var[:1]
    this.Var = this.Var[1:]
    return a[0]
}


/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
```
