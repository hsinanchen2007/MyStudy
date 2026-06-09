### 解题思路
此处撰写解题思路

### 代码

```golang
type CQueue struct {
    in []int
    num int 
}


func Constructor() CQueue {
    return CQueue{}
}


func (this *CQueue) AppendTail(value int)  {
    this.in = append(this.in,value)
}


func (this *CQueue) DeleteHead() int {
    if len(this.in) == 0 {
        return -1
    }

    if len(this.in) == this.num {
        return -1
    }

    defer func() {
        this.num ++
    }()
    
    return this.in[this.num]    
}


/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
```