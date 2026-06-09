```
// 用 栈保存 最后再倒出来 
func reverseList(head *ListNode) *ListNode {
	if head==nil{
		return nil
	}
	stack := make([]*ListNode, 0)
	for head.Next != nil {

		stack = append(stack, head)
		head = head.Next

	}
	res:=head
	for len(stack) != 0 {
		head.Next = stack[len(stack)-1]
		head = head.Next
		stack = stack[0 : len(stack)-1]
	}
	head.Next=nil
	return res
}

// 迭代 
func reverseList1(head *ListNode) *ListNode {
	var prev *ListNode
	var curr *ListNode=head
	for curr!=nil{
		temp:=curr.Next
		curr.Next=prev
		prev =curr
		curr=temp
	}
	return prev

}

// 递归 
func reverseList2(head *ListNode) *ListNode {
	// 编译不通过
	if head == nil&&head.Next==nil {
		return head
	}
	res:=reverseList2(head.Next)
	head.Next.Next=head
	head.Next=nil
	return res


}

```
