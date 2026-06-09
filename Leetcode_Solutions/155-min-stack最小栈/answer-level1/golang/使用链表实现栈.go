# 对于创建栈来说。使用链表更加合适
```
type Node struct{
    Val int
    MinVal int
    Next *Node
}

type MinStack struct {
    dummy *Node
}


/** initialize your data structure here. */
func Constructor() MinStack {
    return MinStack{&Node{-1,math.MinInt32,nil}}
}


func (this *MinStack) Push(x int)  {
    //栈为空时
    if this.dummy.Next==nil{
        node:=&Node{x,x,nil}
        node.Next=this.dummy.Next
        this.dummy.Next=node
    }else{
        //不为空时
        tmp:=this.dummy.Next.MinVal
        if tmp<x{
            node:=&Node{x,tmp,nil}
            node.Next=this.dummy.Next
            this.dummy.Next=node
        }else{
            node:=&Node{x,x,nil}
            node.Next=this.dummy.Next
            this.dummy.Next=node
        }
        
    }
    
}


func (this *MinStack) Pop()  {
    this.dummy.Next=this.dummy.Next.Next
}


func (this *MinStack) Top() int {
    return this.dummy.Next.Val
}


func (this *MinStack) GetMin() int {
    return this.dummy.Next.MinVal
}

```
