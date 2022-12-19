### 解题思路
执行用时 :244 ms, 在所有 Go 提交中击败了60.89%的用户
内存消耗 :8.1 MB, 在所有 Go 提交中击败了100.00%的用户

### 代码

```golang
type CQueue struct {
    Queue []int
    Head int
}


func Constructor() CQueue {
    array := make([]int, 0)
    return CQueue{Queue:array, Head:0}
}


func (this *CQueue) AppendTail(value int)  {
    this.Queue = append(this.Queue, value)
}


func (this *CQueue) DeleteHead() int {
    temp := this.Head
    if temp+1 > len(this.Queue) {
        return -1
    }else {
        //每成功取出一个head往后移动一位
        this.Head = this.Head + 1
        return this.Queue[temp]
    }
}


/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */
```