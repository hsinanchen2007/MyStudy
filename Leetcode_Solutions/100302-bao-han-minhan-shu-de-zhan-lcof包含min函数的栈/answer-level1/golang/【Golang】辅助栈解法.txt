# 解题思路
**暴力法：调用min则遍历栈，查找出其中最小的数值，这里不符合题目要求，不做演示。**

## 栈
- **特点：先进后出**

 - **题目中需要实现的方法** 
  	- push()：在数组的末属添加一个或多个元素（压入栈中）
  	- top()：返回数组中的最后一个元素（栈顶元素），但不出栈 
  	- pop()：删除数组中的最后一个元素（栈顶元素出栈）


## 解题
包含min函数的栈，其实就是比栈多了一个min方法，调用则返回栈中的最小值。

所以只需要增加一个辅助栈来存储较小的值，调用min()返回辅助栈的栈top即为最小值。

---
# 代码
--执行时间：24 ms 	--消耗内存：8.5 MB
```go
type MinStack struct {
    nums []int 	//储存栈
    min []int 	//辅助储存栈，存储最小值
}

/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{
        make([]int,0,3),
        make([]int,0,3),
    }
}

func (this *MinStack) Push(x int)  {
    this.nums=append(this.nums,x)
    if len(this.min)==0{
        this.min=append(this.min,x)
    }else if this.min[len(this.min)-1]<x{
        this.min=append(this.min,this.min[len(this.min)-1])
    }else{
        this.min=append(this.min,x)
    }
}


func (this *MinStack) Pop()  {
    this.nums=this.nums[:len(this.nums)-1]
    this.min=this.min[:len(this.min)-1]
}


func (this *MinStack) Top() int {
    return this.nums[len(this.nums)-1]
}


func (this *MinStack) Min() int {
    return this.min[len(this.min)-1]
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