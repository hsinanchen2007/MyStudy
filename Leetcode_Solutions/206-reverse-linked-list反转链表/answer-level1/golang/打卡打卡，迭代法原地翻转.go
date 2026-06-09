看代码就完事了
```go
func reverseList(head *ListNode) *ListNode {
	prev,cur := &ListNode{},head
	prev = nil
	for cur != nil{
		cur.Next,prev,cur = prev,cur,cur.Next
	}
	return prev
}
```
