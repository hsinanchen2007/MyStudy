哑节点是个好东西，解链表问题神器！

```go []
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{}
	curr := dummy

	for l1 != nil && l2 != nil {
		if l1.Val > l2.Val {
			curr.Next = &ListNode{Val: l2.Val}
			l2 = l2.Next
		} else {
			curr.Next = &ListNode{Val: l1.Val}
			l1 = l1.Next
		}

		curr = curr.Next
	}

	if l1 != nil {
		curr.Next = l1
	}

	if l2 != nil {
		curr.Next = l2
	}

	return dummy.Next
}
```