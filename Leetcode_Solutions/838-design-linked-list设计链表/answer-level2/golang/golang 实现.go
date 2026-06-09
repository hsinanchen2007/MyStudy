type MyLinkedList struct {
    Root *LinkedListNode
    Size int
}

type LinkedListNode struct {
    Val int
    Next *LinkedListNode
    Front *LinkedListNode
}

/** Initialize your data structure here. */
func Constructor() MyLinkedList {
    dummy := new(LinkedListNode)
    dummy.Front, dummy.Next = nil, nil
    dummy.Val = 0

    return MyLinkedList{
        Root: dummy,
        Size: 0,
    }
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
func (this *MyLinkedList) Get(index int) int {
    if this.Size-1 < index {
        return -1
    }
    // dummyNode
    tmp := this.Root
    for index >= 0 {
        index--
        tmp = tmp.Next
    }
    return tmp.Val
}


func (this *MyLinkedList) PrintLinkedList() {
    tmp := this.Root.Next
    for tmp != nil {
        fmt.Println(tmp.Val)
        tmp = tmp.Next
    }
    return
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
func (this *MyLinkedList) AddAtHead(val int)  {

    nextNode := this.Root.Next

    newNode := &LinkedListNode{
        Val: val,
        Next: nextNode,
        Front: this.Root,
    }
    if nextNode != nil {
        nextNode.Front = newNode
    }
    this.Root.Next = newNode
    this.Size++
    return 
}


/** Append a node of value val to the last element of the linked list. */
func (this *MyLinkedList) AddAtTail(val int)  {
    tmp := this.Root
    for tmp.Next != nil {
        tmp = tmp.Next
    }
    newNode := new(LinkedListNode)
    newNode.Front = tmp
    newNode.Next = nil
    newNode.Val = val
    tmp.Next = newNode
    this.Size++
    return 
}


/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
func (this *MyLinkedList) AddAtIndex(index int, val int)  {
    if index <= 0 {
        this.AddAtHead(val)
        return 
    }
    if this.Size == index {
        this.AddAtTail(val)
        return
    }
    if this.Size <= index-1 {
        return 
    }


    tmp := this.Root
    newNode := new(LinkedListNode)
    newNode.Val = val

    for tmp.Next != nil && index >= 0 {
        tmp = tmp.Next
        index--
    }

    node := tmp.Front
    node.Next = newNode
    newNode.Front = node
    newNode.Next = tmp
    tmp.Front = newNode
    this.Size++
    return
}


/** Delete the index-th node in the linked list, if the index is valid. */
func (this *MyLinkedList) DeleteAtIndex(index int)  {
    if index > this.Size || index < 0 {
        return
    }
    // dummyNode
    tmp := this.Root
    for tmp != nil && index>=0 {
        tmp = tmp.Next
        index--
    }
    if tmp == nil {
        return
    }
    frontNode := tmp.Front
    nextNode := tmp.Next
    frontNode.Next = nextNode
    if nextNode != nil {
        nextNode.Front = frontNode
    }
    this.Size--
    return 
}


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */