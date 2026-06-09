```
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	tmp := head
	for tmp != nil {
		if tmp.Next == nil {
			break
		}

		for tmp.Val == tmp.Next.Val {
			*tmp = *tmp.Next
			if tmp.Next == nil {
				break
			}
		}

		tmp = tmp.Next

	}

	return head
}
```