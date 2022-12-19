### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var dummy = &ListNode{Val: -1}
	dummy.Next = head
	var q = dummy
	for head != nil && head.Next != nil {
		if head.Val != head.Next.Val {
			q = head
			head = head.Next
		} else {
			for head != nil && head.Next != nil && head.Val == head.Next.Val {
				head = head.Next
			}
			q.Next = head.Next
			head = head.Next
		}
	}
	return dummy.Next
}
```