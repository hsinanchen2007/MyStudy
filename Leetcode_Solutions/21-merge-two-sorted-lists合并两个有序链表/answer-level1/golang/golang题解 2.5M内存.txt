
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	var pre *ListNode
	cur1 := l1
	cur2 := l2
	head := l1
	if l2.Val < l1.Val {
		head = l2
		cur1 = l2
		cur2 = l1
	}
	for {
		if cur1 == nil {
			pre.Next = cur2
			break
		}
		if cur2 == nil {
			pre.Next = cur1
			break
		}
		if cur1.Val <= cur2.Val {
			pre = cur1
			cur1 = cur1.Next
		} else {
			next := cur2.Next
			pre.Next = cur2
			cur2.Next = cur1
			pre = cur2
			cur2 = next
		}

	}

	return head
}