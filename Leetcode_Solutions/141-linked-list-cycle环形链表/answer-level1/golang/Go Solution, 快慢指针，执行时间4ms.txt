```Golang
func hasCycle(head *ListNode) bool {
	if head == nil  || head.Next == nil {
		return false
	}
	// 快慢指针
	slow := head.Next
	fast := slow.Next

	for  slow != fast {
		if slow == nil || fast == nil {
			return false
		}
		
		slow = slow.Next
		if fast.Next != nil {
			fast = fast.Next.Next
		} else {
			return false
		}
	}
	return true
}
```
