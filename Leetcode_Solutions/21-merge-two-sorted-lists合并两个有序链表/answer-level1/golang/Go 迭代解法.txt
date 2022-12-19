时间复杂度：O(n)
空间复杂度：O(1)

```
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	prehead := &ListNode{}
	prev := prehead

	for l1 != nil || l2 != nil {
		if l1 == nil || (l2 != nil && l1.Val > l2.Val) {
			prev.Next = l2
			prev = l2
			l2 = l2.Next
		} else {
			prev.Next = l1
			prev = l1
			l1 = l1.Next
		}
	}

	return prehead.Next
}
```
