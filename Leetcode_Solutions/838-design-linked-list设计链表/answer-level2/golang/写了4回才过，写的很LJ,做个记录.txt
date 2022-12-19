type Node struct {
	Val int
	Next *Node
}

type MyLinkedList struct {
	head *Node
	count int
}


/** Initialize your data structure here. */
func Constructor() MyLinkedList {
	return MyLinkedList{}
}


/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
func (this *MyLinkedList) Get(index int) int {
	if index < 0 || index >= this.count{
		return -1
	}
	n := -1
	node := this.head
	for index >= 0{
		if node == nil{
			return -1
		}
		n = node.Val
		node = node.Next
		index -= 1
	}
	return n
}


/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
func (this *MyLinkedList) AddAtHead(val int)  {
	if this.head == nil {
		this.head = &Node{Val:val}
		this.head.Next = nil
	}else {
		nextHead := this.head
		this.head = &Node{Val:val}
		this.head.Next = nextHead
	}
	this.count += 1
}


/** Append a node of value val to the last element of the linked list. */
func (this *MyLinkedList) AddAtTail(val int)  {
	if this.head == nil {
		this.head = &Node{Val:val}
		this.head.Next = nil
	}else {
		preNode := this.head
		for this.head.Next != nil{
			this.head = this.head.Next
		}
		this.head.Next = &Node{Val:val}
		this.head = preNode
	}
	this.count += 1
}


/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
func (this *MyLinkedList) AddAtIndex(index int, val int)  {
	if index <= 0{
		this.AddAtHead(val)
		return
	}
	if index == this.count{
		this.AddAtTail(val)
		return
	}
	node := this.head
	preNode := new(Node)
	p := preNode
	for index > 0 {
		if node == nil {
			return
		}
		nextNode := node.Next
		node.Next = nil
		preNode.Next = node
		node = nextNode
		preNode = preNode.Next
		index -= 1
	}
	preNode.Next = &Node{Val:val}
	preNode.Next.Next = node
	this.head = p.Next
	this.count += 1
}


/** Delete the index-th node in the linked list, if the index is valid. */
func (this *MyLinkedList) DeleteAtIndex(index int)  {
	if index < 0{
		return
	}
	if index == 0{
		if this.head == nil {
			return
		}
		this.head = this.head.Next
		this.count -= 1
		return
	}
	node := this.head
	preNode := new(Node)
	p := preNode
	for index > 0 {
		if node == nil {
			return
		}
		nextNode := node.Next
		node.Next = nil
		preNode.Next = node
		preNode = preNode.Next
		node = nextNode
		index -= 1
	}
	if node == nil{
		return
	}
	preNode.Next = node.Next
	this.head = p.Next
	this.count -= 1
}