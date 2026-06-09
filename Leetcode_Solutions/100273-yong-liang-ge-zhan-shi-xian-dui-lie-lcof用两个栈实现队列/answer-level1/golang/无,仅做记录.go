### 解题思路
该题对 go 无场景, 无实际意义

### 代码

```golang
type CQueue struct {
    q []int
}

func Constructor() CQueue {
    return CQueue{}
}


func (this *CQueue) AppendTail(value int)  {
    this.q = append(this.q, value)
}


func (this *CQueue) DeleteHead() int {
    if len(this.q) == 0 {
            return -1
    }

    i := this.q[0]
    this.q = this.q[1:]
    return i 
}


/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
```