知识点：
初始化一个不为nil的链表头和一个指向链表尾的指针（方便往链表尾部插入数据）
```
func AddTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var res *ListNode

	if l1 != nil && l2 != nil {
		res = add(l1, l2)
	}

	return res
}

func add(l1 *ListNode, l2 *ListNode) *ListNode {
	res := &ListNode{Val: 0}
	var value, carry int

	work := res
	for l1 != nil && l2 != nil {
		value = l1.Val + l2.Val + carry

		l1 = l1.Next
		l2 = l2.Next

		if value >= 10 {
			work.Next = &ListNode{Val: value - 10}
			carry = 1
		} else {
			work.Next = &ListNode{Val: value}
			carry = 0
		}

		work = work.Next
	}

	for l1 != nil || l2 != nil {
		if l1 != nil {
			value = l1.Val + carry
			l1 = l1.Next
		} else if l2 != nil {
			value = l2.Val + carry
			l2 = l2.Next
		}

		if value >= 10 {
			work.Next = &ListNode{Val: value - 10}
			carry = 1
		} else {
			work.Next = &ListNode{Val: value}
			carry = 0
		}

		work = work.Next
	}

	if carry != 0 {
		work.Next = &ListNode{Val: carry}
	}

	return res.Next
}
```
