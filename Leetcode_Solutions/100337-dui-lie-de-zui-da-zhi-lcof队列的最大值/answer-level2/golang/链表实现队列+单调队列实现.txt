### 刚开始以为这个题操作都是O(1),怎么做都不对，然后想着先用辅助栈实现一下，当时维护了一个单增栈，实现失败
### 看了官方解题，发现时间复杂度是指均摊下来是O(1),且使用了单减的双端队列实现。（一直在用栈实现的蠢哭了）

### 实现时，采用链表实现队列的入队出队，使用切片模拟双端队列，实现单调队列

```
//使用链表实现一个队列
type Node struct{
    Val int
    Next *Node
}

type MaxQueue struct {
    head *Node
    tail *Node
    dequeue []int//采用双端队列，实现最大值保存
}

func Constructor() MaxQueue {
    dummy:=&Node{-1,nil}
    return MaxQueue{
        head:dummy,
        tail:dummy,
        dequeue:make([]int,0),
    }
}

func (this *MaxQueue) Max_value() int {
    if len(this.dequeue)==0{
        return -1
    }else{
        return this.dequeue[0]
    }
}


func (this *MaxQueue) Push_back(value int)  {
    //入队列
    this.tail.Next=&Node{value,nil}
    this.tail=this.tail.Next
    //核心代码：维护一个单减队列
    //当队列入队顺序为1，2，3，4时，当前的最大值分别为1，2，3，4。即，如果后面入队的数更大，
    //那么队列的最大值由入队这个数实现，前面的就可以省掉。当这个最大值出队时，将其删掉就行
    for len(this.dequeue)!=0 && value > this.dequeue[len(this.dequeue)-1]{
        this.dequeue=this.dequeue[:len(this.dequeue)-1]//出队
    }
    this.dequeue=append(this.dequeue,value)
}


func (this *MaxQueue) Pop_front() int {
    if this.head==this.tail{
        return -1
    }else{
        //出队列
        tmp:=this.head.Next.Val
        if this.head.Next==this.tail{
            this.tail=this.head
        }
        this.head.Next=this.head.Next.Next
        //如果出队列的数和双端队列的队头相等，则把队头出队
        if tmp==this.dequeue[0]{
            this.dequeue=this.dequeue[1:]
        }
        return tmp
    }  
}
```
