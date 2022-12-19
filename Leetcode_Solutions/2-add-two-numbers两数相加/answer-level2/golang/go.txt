### 解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	i := 0 // 进阶位

	l1Cur := l1
	l2Cur := l2
	l1Par := l1

	for l1Cur != nil || l2Cur != nil {
		x := 0
		if l1Cur != nil {
			x = l1Cur.Val
		}

		y := 0
		if l2Cur != nil {
			y = l2Cur.Val
		}

		if l1Cur == nil {
			l1Par.Next = &ListNode{}
			l1Cur = l1Par.Next
		}

		sum := x + y + i
		l1Cur.Val = sum % 10
		i = sum / 10

		l1Par = l1Cur

		if l1Cur != nil {
			l1Cur = l1Cur.Next
		}

		if l2Cur != nil {
			l2Cur = l2Cur.Next
		}

	}

	if i != 0 {
		if l1Cur == nil {
			l1Par.Next = &ListNode{}
			l1Cur = l1Par.Next
		}
		l1Cur.Val = i
	} else {
		l1Par.Next = nil
	}

	return l1
}

```