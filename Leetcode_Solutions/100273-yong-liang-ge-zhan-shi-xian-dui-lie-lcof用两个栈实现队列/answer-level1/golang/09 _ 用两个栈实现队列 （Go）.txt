# 思路
- 定义两个栈：in 栈存数据，out 栈出数据。
- 入队列：直接入 in 栈。
- 出队列：
    - 如果两个栈都为空，返回 -1。
    - 如果 out 栈为空，将 in 栈依次弹出并入 out 栈。
    - 如果 out 栈不为空，弹出 out 栈栈顶元素

# 代码
```
type CQueue struct {
    in []int    // in 栈：存数据 
    out []int   // out 栈：出数据
}


func Constructor() CQueue {
    return CQueue {}
}


func (this *CQueue) AppendTail(value int)  {
    // 直接入 int 栈
    this.in = append(this.in, value)
}


func (this *CQueue) DeleteHead() int {
    // 两个栈都为空
    if len(this.out) == 0 && len(this.in) == 0 {
        return -1
    }
    
    // out 栈为空，依次弹出 in 栈栈顶元素，入 out 栈
    if len(this.out) == 0 {
        for len(this.in) > 0 {
            lastIndex := len(this.in) - 1
            popValue := this.in[lastIndex]
            this.in = this.in[:lastIndex]
            this.out = append(this.out, popValue)
        }
    }
    
    // 弹出 out 栈顶元素
    lastIndex := len(this.out) - 1
    popValue := this.out[lastIndex]
    this.out = this.out[:lastIndex]
    return popValue
}
```
