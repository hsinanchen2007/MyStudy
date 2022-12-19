![图片.png](https://pic.leetcode-cn.com/0cb85c1dc874ed031094c2b6b5eee3defe646d9b384f8bd8833ec40bef039655-%E5%9B%BE%E7%89%87.png)


这道提的主要是难点是获取当前栈的最小值，在每次入栈的时候 将入栈数据节点化，就是增加一个当前栈顶最小值

```
type MinStack struct {
    s []Node
}
type Node struct {
	d int //data
	m int //current min
}


/** initialize your data structure here. */
func Constructor() MinStack {
   return MinStack{}
}


func (this *MinStack) Push(x int)  {
	d := Node{d:x,m:x}
	if len(this.s)>0 &&this.s[len(this.s)-1].m< x{
		d.m=this.s[len(this.s)-1].m
	}
     this.s = append(this.s,d)

}


func (this *MinStack) Pop()  {
	this.s = this.s[:len(this.s)-1]
}


func (this *MinStack) Top() int {
	return this.s[len(this.s)-1].d
}


func (this *MinStack) GetMin() int {
	return this.s[len(this.s)-1].m
}
```
