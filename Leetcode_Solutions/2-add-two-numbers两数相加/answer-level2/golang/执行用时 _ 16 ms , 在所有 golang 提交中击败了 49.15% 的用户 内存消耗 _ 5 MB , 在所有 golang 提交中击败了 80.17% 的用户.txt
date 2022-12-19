#### 预先创建下一个结点，如果之前结点相加超过10，也创建下一个即将进位的结点并加上1
```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var list = new(ListNode)
	var cur = list
	var a, b int
	for l1 != nil || l2 != nil {
		a = 0
		b = 0
		if l1 != nil {
			a = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			b = l2.Val
			l2 = l2.Next
		}
		v := a + b
		if cur.Next == nil {
			cur.Next = &ListNode{}
		}
		if v+cur.Next.Val >= 10 {
			v = v - 10
			cur.Next.Next = &ListNode{
				Val: 1,
			}

		}
		cur.Next.Val += v
		cur = cur.Next
	}
	return list.Next
}
```
