### 解题思路
此处撰写解题思路

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
   l3 := new(ListNode)
	if l1 == nil && l2 == nil {
		return l3
	} else if l1 == nil {
		l3 = l2
		return l3
	} else if l2 == nil {
		l3 = l1
		return l3
	}

	l4 := l3
	var carry int = 0
	for l1 != nil || l2 != nil {
		var a1 int = 0
		// 判断l1是否空指针
		if l1 != nil {
			a1 = l1.Val
			l1 = l1.Next
		}
		var a2 int = 0
		if l2 != nil {
			a2 = l2.Val
			l2 = l2.Next
		}
		sum := a1 + a2 + carry
		carry = sum / 10
		sum %= 10
		l4.Val = sum
		if l1 != nil || l2 != nil {
			if l1 == nil {
				l4.Next = l2
			} else if l2 == nil {
				l4.Next = l1
			} else {
				l4.Next = &ListNode{}
			}
			l4 = l4.Next
		}
	}
	if carry == 1 {
		l4.Next = &ListNode{
			Val:  carry,
			Next: nil,
		}
	}
	return l3
}
```