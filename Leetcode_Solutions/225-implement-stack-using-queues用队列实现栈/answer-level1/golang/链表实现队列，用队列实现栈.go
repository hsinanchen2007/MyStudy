## 使用链表实现队列，通过所实现的队列实现栈

```
type MyStack struct {
    Input *Queue//管入栈
    Output *Queue//管出栈
}
/** Initialize your data structure here. */
func Constructor() MyStack {
    return MyStack{
        Input:NewQueue(),
        Output:NewQueue(),
    }
}
/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
    this.Input.Push(x)
}
/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
    if this.Output.Len()==0{
        this.Input,this.Output=this.Output,this.Input
    }
    for this.Output.Len()>1{
        this.Input.Push(this.Output.Pop())
    }
    return this.Output.Pop()  
}


/** Get the top element. */
func (this *MyStack) Top() int {
    topNum:=this.Pop()
    this.Input.Push(topNum)
    return topNum
}
/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
    if this.Input.IsEmpty() && this.Output.IsEmpty(){
        return true
    }
    return false
}

//用链表构建一个队列
type Node struct{
    Val int
    Next *Node
}
type Queue struct{
    head *Node
    tail *Node
}
func NewQueue()*Queue{
    dummy:=&Node{-1,nil}
    return &Queue{dummy,dummy}
}
//队列的插入
func (q *Queue)Push(x int){
    node:=&Node{x,nil}
    q.tail.Next=node
    q.tail=q.tail.Next
}
//队列出队
func (q *Queue)Pop()int{
    val:=q.head.Next.Val
    if q.head.Next==q.tail{
        q.tail=q.head
    }
    q.head.Next=q.head.Next.Next
    return val
}
func (q *Queue)Len()int{
    res:=0
    cur:=q.head
    for cur!=q.tail{
        res++
        cur=cur.Next
    }
    return res
}
//队列是否为空
func (q *Queue)IsEmpty()bool{
    if q.head==q.tail{
        return true
    }else{
        return false
    }
}
```
