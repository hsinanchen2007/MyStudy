```
func swapPairs(head *ListNode) *ListNode {
	var pre *ListNode=&ListNode{0,head}
    head=pre
	for head.Next!=nil&&head.Next.Next!=nil{
		a:=head.Next
		b:=head.Next.Next
		head.Next,b.Next,a.Next=b,a,b.Next
		head=a
	}
	return pre.Next
}
```
