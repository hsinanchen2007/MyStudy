创建一个辅助节点

```
func swapPairs2(head *ListNode) *ListNode {
	//辅助节点，也是上一个完成交互的对的后一个节点
	tmp := &ListNode{
		Val:  -1,
		Next: nil,
	}
	result := tmp
	tmp.Next = head
	for tmp.Next != nil && tmp.Next.Next != nil {
		pre := tmp.Next
		post := tmp.Next.Next
		pre.Next = post.Next
		post.Next = pre
		tmp.Next = post
		tmp = pre
	}
	return result.Next
}

```
