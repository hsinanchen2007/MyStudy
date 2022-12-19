type MyLinkedList struct {
    head *Node
    len int
}

type Node struct {
    Value int
    next *Node
}

// 没招啦，只能这样了，实现是简单，但是性能是真的不怎么样啊
func Constructor() MyLinkedList {
    return MyLinkedList{head:&Node{}}
}

func (this *MyLinkedList) Get(index int) int {
    if index < 0 || index > this.len -1 {
        return -1
    }
    temp := this.head
    for i:=0;i<=index;i++ {
        temp = temp.next
    }
    return temp.Value
}

func (this *MyLinkedList) AddAtHead(val int)  {
    this.AddAtIndex(0,val)
}

func (this *MyLinkedList) AddAtTail(val int)  {
    this.AddAtIndex(this.len,val)
}


func (this *MyLinkedList) AddAtIndex(index int, val int)  {
    if index > this.len {
        return
    }
    // if index < 0 {
    //     index = 0
    // }
    temp := this.head
    for i:=0;i<index;i++ {
        temp = temp.next
    }
    t := temp.next
    temp.next = &Node{Value:val,next:t}
    this.len++
}

func (this *MyLinkedList) DeleteAtIndex(index int)  {
    if index < -1 || index > this.len-1{
        return
    }
    temp := this.head
    for i:=0;i<index;i++ {
        temp = temp.next
    }
    t := temp.next
    temp.next = temp.next.next
    t.next = nil
    this.len--
}
