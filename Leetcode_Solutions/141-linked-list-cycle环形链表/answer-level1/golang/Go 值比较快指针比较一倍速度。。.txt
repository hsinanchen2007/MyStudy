比较奇怪，用 Go 写，如果比较值，速度可以比比较指针快一倍。

这段代码要 8ms：

```
func hasCycle(head *linkedlist.ListNode) bool {
	var (
		fast = head
		slow = head
	)

	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			return true
		}
	}

	return false
}
```


这段代码只要 4ms：

```
func hasCycle(head *linkedlist.ListNode) bool {
	var (
		fast = head
		slow = head
	)

	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast != nil && fast.Val == slow.Val {
			return true
		}
	}

	return false
}
```
