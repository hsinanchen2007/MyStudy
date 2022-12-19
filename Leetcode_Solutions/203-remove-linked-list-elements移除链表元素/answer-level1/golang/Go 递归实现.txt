递归遍历链表，下一节点值与指定值相等时，将指向下一个节点的指针指向下下个节点。

```
 执行用时 : 8 ms, 在Remove Linked List Elements的Go提交中击败了98.80% 的用户
 内存消耗 : 5.4 MB, 在Remove Linked List Elements的Go提交中击败了6.12% 的用户
```
```Go []
func removeElements(head *ListNode, val int) *ListNode {
	if head == nil {
		return nil
	} else if head.Next == nil {
		if head.Val == val {
			return head.Next
		}
		return head
	} else {
		if val == head.Next.Val {
			head.Next = head.Next.Next
			removeElements(head, val)
		} else {
			removeElements(head.Next, val)
		}
	}
	if head.Val == val {
		return head.Next
	}
	return head
}