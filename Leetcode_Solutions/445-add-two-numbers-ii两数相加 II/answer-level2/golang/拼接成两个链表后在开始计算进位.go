```go
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l1count := 0
	l2count := 0
	remain := 0

	l1copy := l1
	l2copy := l2

	for l1copy != nil {
		l1copy = l1copy.Next
		l1count++
	}
	for l2copy != nil {
		l2copy = l2copy.Next
		l2count++
	}
	l1copy = l1
	l2copy = l2

	var firstPartNode *ListNode
	var secondPartNode *ListNode

	firstPartNode = &ListNode{Val: 0}
	firstPartNodeHead := firstPartNode

	secondPartNode = &ListNode{Val: 0}
	secondPartNodeHead := secondPartNode
	// 两个链表不平的部分，复制到新的链表firstPartNode
	if l1count != l2count {
		if l1count > l2count {
			for i := 0; i < l1count-l2count; i++ {
				firstPartNode.Next = l1copy
				l1copy = l1copy.Next
				firstPartNode = firstPartNode.Next
			}
			remain = l2count
		}

		if l2count > l1count {
			for i := 0; i < l2count-l1count; i++ {
				firstPartNode.Next = l2copy
				l2copy = l2copy.Next
				firstPartNode = firstPartNode.Next
			}
			remain = l1count
		}
	} else {
		remain = l1count
	}
         //  两个链表平的部分，复制到新的链表secondPartNode
	for i := 0; i < remain; i++ {
		if l1copy != nil && l2copy != nil {
			var nd *ListNode
			sum := l1copy.Val + l2copy.Val
			nd = &ListNode{Val: sum}
			secondPartNode.Next = nd
			secondPartNode = secondPartNode.Next
			l1copy = l1copy.Next
			l2copy = l2copy.Next
		}
	}

	// 串联链表
	firstPartNode.Next = secondPartNodeHead.Next

    ls := cleanList(firstPartNodeHead)
    if ls.Val == 0{
        ls = ls.Next
    }
    return ls 
}

// 循环遍历拼接好的新链表，如果大于等于10则向上进位，每一轮循环完检测链表是否还有大于等于10的元素，有则继续循环进位。
func cleanList(l *ListNode) *ListNode {
	loop := true
	head := l
	for loop == true {
		head = l
		var pre *ListNode
		for head != nil {
			if pre == nil {
				pre = head
			}
			if head.Val >= 10 {
				head.Val -= 10
				pre.Val += 1
			}
			pre = head
			head = head.Next
		}
		end := checkList(l)
		if end == true {
			loop = false
		}
	}
	return l
}

// 循环检测链表是否还有大于等于10的元素
func checkList(l *ListNode) bool {
	head := l
	carry := true

	for head != nil {
		if head.Val >= 10 {
			carry = false
			break
		}
		head = head.Next
	}

	return carry
}
```