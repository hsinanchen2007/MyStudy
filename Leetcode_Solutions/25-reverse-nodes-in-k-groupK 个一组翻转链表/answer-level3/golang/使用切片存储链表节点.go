使用切片，分为len(ListNode)/k 组，然后分组反转，存入切片中，最后将切片中节点首尾相连
```
func reverseKGroup(head *ListNode, k int) *ListNode {
 	if head == nil || head.Next == nil {
		return head
	}
	cur := head
	var listLength int
	for head != nil {
		listLength++
		head = head.Next
	}

	reverseGroupNum := (listLength) / k
	if reverseGroupNum == 0 {
		return cur
	}

	var stack = make([]*ListNode, k*reverseGroupNum)
	for i := 0; i < reverseGroupNum; i++ {
		for j := 0; j < k; j++ {
			stack[(i+1)*k-j-1] = cur
			cur = cur.Next
		}
	}
	pre := new(ListNode)
	pre.Next = stack[0]
	for i := range stack {
		if i == (len(stack) - 1) {
			stack[i].Next = cur
			break
		}
		stack[i].Next = stack[i+1]
	}
	return pre.Next
}
```
