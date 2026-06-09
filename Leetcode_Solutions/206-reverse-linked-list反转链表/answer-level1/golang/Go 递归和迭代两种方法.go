1. 迭代法
```
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var prev *ListNode
	cur := head

	for cur != nil {
		cur.Next, prev, cur = prev, cur, cur.Next
	}

	return prev
}
```
2. 递归法
```
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	prev := reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil

	return prev
}
```