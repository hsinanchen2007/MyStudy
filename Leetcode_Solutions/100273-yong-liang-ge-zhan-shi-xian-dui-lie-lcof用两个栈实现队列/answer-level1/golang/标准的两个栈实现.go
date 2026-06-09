### 解题思路
此处撰写解题思路
用两个切片作为栈进行append、[ : ]处理。
### 代码

```golang
type CQueue struct {
    s1 []int
    s2 []int
}


func Constructor() CQueue {
    return CQueue{}
}


func (this *CQueue) AppendTail(value int)  {
    this.s1 = append(this.s1,value)
}


func (this *CQueue) DeleteHead() int {
    var tmp int
    for i := len(this.s1)-1;i>=0;i--{
        this.s2 = append(this.s2,this.s1[i])
        this.s1 = this.s1[:len(this.s1)-1]
    }
    if len(this.s2)>0{
        tmp = this.s2[len(this.s2)-1]
        this.s2 = this.s2[:len(this.s2)-1]
    }else{
        return -1
    }
    for i := len(this.s2)-1;i>=0;i--{
        this.s1 = append(this.s1,this.s2[i])
        this.s2 = this.s2[:len(this.s2)-1]
    }
    return tmp
}


/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
```