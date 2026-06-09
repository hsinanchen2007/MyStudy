

### 代码

```golang
func reverseList(head *ListNode) *ListNode {
	if head != nil && head.Next != nil {
		ptr := head.Next
		head.Next = nil
		pre := head
		for ptr.Next != nil {
			tmp := ptr.Next
			ptr.Next, pre = pre, ptr
			ptr = tmp
		}
		ptr.Next = pre
		return ptr
	}
	return head
}
```