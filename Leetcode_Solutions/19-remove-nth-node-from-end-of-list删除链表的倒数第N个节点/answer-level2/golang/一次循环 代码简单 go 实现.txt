```
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if n < 1 || head == nil {
		return head
	}
	for node, remove, i, j := head, head, 0, n; ; i++ {
		if node, j = node.Next, j-1; node == nil {
			if j == 0 {
				return head.Next
			} else if j > 0 {
				return head
			}
			remove.Next = remove.Next.Next
			return head
		}
		if i > n-1 {
			remove = remove.Next
		}
	}
}

```
