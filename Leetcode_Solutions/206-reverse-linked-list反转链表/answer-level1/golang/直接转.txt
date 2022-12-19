### 代码

```golang
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	var newHead *ListNode = nil
	for head.Next != nil {
		tmp := head.Next
		head.Next = newHead
		newHead = head
		head = tmp
	}

	head.Next = newHead
	return head
}
```