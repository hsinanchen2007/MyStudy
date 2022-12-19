```
func deleteNode(node *ListNode) {
	if node == nil {
		return
	}

	next := node.Next
	if next != nil {
		node.Next = next.Next
		node.Val = next.Val
	}
}
```
