```
func middleNode(head *ListNode) *ListNode {
	a, b := head, head
	for b != nil && b.Next != nil {
		b, a = b.Next.Next, a.Next
	}
	return a
}
```
