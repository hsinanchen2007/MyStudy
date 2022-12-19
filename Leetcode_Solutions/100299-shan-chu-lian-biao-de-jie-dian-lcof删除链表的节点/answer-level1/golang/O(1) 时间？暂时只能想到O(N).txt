```
func deleteNode(head *ListNode, val int) *ListNode {
	if nil == head {
		return nil
	} else if head.Val == val {
		return head.Next
	}
	for n, p := head.Next, head; nil != n; n, p = n.Next, n {
		if n.Val == val {
			p.Next = n.Next
			return head
		}
	}
	return head
}
```