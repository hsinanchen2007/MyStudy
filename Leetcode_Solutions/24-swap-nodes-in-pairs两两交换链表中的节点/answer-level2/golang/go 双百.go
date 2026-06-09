```
func swapPairs(head *ListNode) *ListNode {
	prev := &ListNode{
		Val:  0,
		Next: head,
	}
	cur := prev
	temp := head
	for head != nil && head.Next!=nil{
		head = head.Next.Next
		cur.Next = temp.Next
		cur.Next.Next = temp
		cur = temp
		cur.Next = nil
		temp  = head
	}
	if head != nil && head.Next == nil{
		cur.Next = head
	}
	return prev.Next
}
```
