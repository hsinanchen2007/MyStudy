```
func insertionSortList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	var (
		newHead   = head
		tmp, tmp2 *ListNode
	)

	head = head.Next
	newHead.Next = nil
	for head != nil {
		if newHead.Val > head.Val {
			tmp = head.Next
			head.Next = newHead
			newHead = head
			head = tmp
		} else {
			tmp = newHead
			for tmp.Next != nil && tmp.Next.Val < head.Val {
				tmp = tmp.Next
			}
			if tmp.Next == nil {
				tmp2 = head.Next
				head.Next = nil
				tmp.Next = head
				head = tmp2
			} else {
				tmp2 = head.Next
				head.Next = tmp.Next
				tmp.Next = head
				head = tmp2
			}
		}
	}

	return newHead
}

```
