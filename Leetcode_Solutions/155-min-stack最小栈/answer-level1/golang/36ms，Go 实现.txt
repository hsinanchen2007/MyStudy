![image.png](https://pic.leetcode-cn.com/9f3da51d6f7f056a8ac71fa1e6ee0cfaeed9acef9e5eb3feedeeda749868a90c-image.png)

开两个切片作为栈，一个存储入栈元素，一个存储当前层次最小元素。这样可以 O(1) 时间复杂度获取栈中最小元素。

代码：
```
type MinStack struct {
    data   []int    // 存储入栈数据
    min    []int    // 存储当前栈中最小元素
}


/** initialize your data structure here. */
func Constructor() MinStack {
    ms := MinStack{}
    return ms
}


func (this *MinStack) Push(x int)  {
    this.data = append(this.data, x)
    min := x
    if len(this.min)!=0 {
        min = this.min[len(this.min)-1]    // 当前最小元素
        if x < min {
            min = x
        }
    }
    this.min = append(this.min, min)
}


func (this *MinStack) Pop()  {
    this.data = this.data[:len(this.data)-1]
    this.min = this.min[:len(this.min)-1]
}


func (this *MinStack) Top() int {
    return this.data[len(this.data)-1]
}


func (this *MinStack) GetMin() int {
    return this.min[len(this.min)-1]
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