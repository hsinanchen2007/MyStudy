func rotateRight(head *ListNode, k int) *ListNode {
   var (
		pre        *ListNode
		post       *ListNode
		removeStep int // 从头节点移动的步长
		size       int    // 链表总长
		thead      *ListNode
		i          int
	)

	if head == nil || head.Next == nil {
		return head
	}
 
	size = 1
	pre = head
	for pre.Next != nil {
		size++
		pre = pre.Next
	}
	post = pre

	k = k % size
	if k == 0 {
		return head
	}
	
	removeStep = size - k
	thead = &ListNode{
		Val:  0,
		Next: head,
	}
    
    // 找到断链的节点
	pre = head
	for i = 1; i < removeStep; i++ {
		pre = pre.Next
	}

    // 断链处理
	thead.Next = pre.Next
	post.Next = head
	pre.Next = nil

	return thead.Next
}