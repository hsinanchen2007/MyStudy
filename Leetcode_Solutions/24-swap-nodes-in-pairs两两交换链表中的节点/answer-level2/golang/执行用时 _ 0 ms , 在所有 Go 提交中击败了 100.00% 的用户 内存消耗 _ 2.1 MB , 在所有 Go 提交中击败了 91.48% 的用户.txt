不一定递归吧，三个指针就好了
```
func swapPairs(head *ListNode) *ListNode {
	if head==nil {
		return nil
	}
	if head.Next==nil{
		return head
	}
	res:=head.Next
	temp1:=head
	temp2:=head.Next
	var temp3 *ListNode
	for temp2!=nil {
		temp1.Next=temp2.Next
		temp2.Next=temp1
		if temp3!=nil {
			temp3.Next=temp2
		}
		temp3=temp1
		if temp1.Next!=nil {
			temp1=temp1.Next
		}
		temp2=temp1.Next
	}
	return res
}
```
