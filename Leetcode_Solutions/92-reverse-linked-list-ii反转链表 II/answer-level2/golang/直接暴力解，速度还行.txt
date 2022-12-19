```
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	var (
		newHead *ListNode = nil
		tmpHead *ListNode = nil
		newCurr *ListNode = nil
	)

	if head == nil || head.Next == nil {
		return head
	}

	for i := 0; i < m-1; i++ {
		if newHead == nil {
			newHead = head
		} else {
			newCurr.Next = head
		}
		newCurr = head
		head = head.Next
	}

	for i := m - 1; i < n; i++ {
		tmp := head.Next
		head.Next = tmpHead
		tmpHead = head
		head = tmp
	}
	for tmpHead != nil {
		if newHead == nil {
			newHead = tmpHead
			newCurr = tmpHead
		} else {
			newCurr.Next = tmpHead
			newCurr = tmpHead
		}
		tmpHead = tmpHead.Next
	}
	for head != nil {
		if newHead == nil {
			newHead = head
			newCurr = head
		} else {
			newCurr.Next = head
			newCurr = head
		}
		head = head.Next
	}
	return newHead
}

```
