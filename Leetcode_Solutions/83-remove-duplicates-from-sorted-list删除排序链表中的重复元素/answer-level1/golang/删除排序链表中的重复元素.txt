思路：直接遍历链表，判断Next是否等于当前节点，如果等于就是重复删除，否则继续遍历知道为nil，
这样整个时间复杂度为$o(n)
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	node := head
	for node.Next != nil {
		if node.Next.Val == node.Val {
			node.Next = node.Next.Next
		} else {
			node = node.Next
		}
	}
	return head
}