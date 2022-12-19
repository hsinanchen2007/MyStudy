本题其实是根据两个链表构造另一个链表，所以需要用到哑节点，那么哑节点的 Next 即我们要求的新链表的头。

```go
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{} // 哑节点的经典用法
	curr := dummy        // 当前指针用于构建节点外加移动

	carry := 0 // 进位

	for l1 != nil && l2 != nil { // 如果 l1 和 l2 都不为空
		sum := carry + l1.Val + l2.Val
		curr.Next = &ListNode{Val: sum % 10} // Next 指向余数
		curr = curr.Next
		carry = sum / 10 // 进位存储商
		l1 = l1.Next
		l2 = l2.Next
	}

	for l1 != nil { // 如果 l1 不空, 继续遍历 l1
		sum := carry + l1.Val
		curr.Next = &ListNode{Val: sum % 10}
		curr = curr.Next
		carry = sum / 10
		l1 = l1.Next
	}

	for l2 != nil { // 如果 l2 不空, 继续遍历 l2
		sum := carry + l2.Val
		curr.Next = &ListNode{Val: sum % 10}
		curr = curr.Next
		carry = sum / 10
		l2 = l2.Next
	}

	if carry > 0 { // 如果进位大于 0, 需要向链表添加一个元素
		curr.Next = &ListNode{Val: carry}
	}

	return dummy.Next
}
```
