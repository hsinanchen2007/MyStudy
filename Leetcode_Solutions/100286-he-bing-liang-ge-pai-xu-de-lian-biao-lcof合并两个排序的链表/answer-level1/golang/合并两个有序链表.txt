### 解题思路
从左到右依次遍历l1和l2，将更小的节点放入新链表中

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	var head, pr *ListNode = nil, nil
	if l1.Val <= l2.Val {
		head = &ListNode{Val: l1.Val}
		l1 = l1.Next
	} else {
		head = &ListNode{Val: l2.Val}
		l2 = l2.Next
	}
	pr = head

	for l1 != nil || l2 != nil {
		if l1 != nil && l2 != nil {
			if l1.Val <= l2.Val {
				pr.Next = &ListNode{Val: l1.Val}
				l1 = l1.Next
			} else if l1.Val > l2.Val {
				pr.Next = &ListNode{Val: l2.Val}
				l2 = l2.Next
			}
			pr = pr.Next
		} else if l1 == nil {
			pr.Next = l2
			break
		} else if l2 == nil {
			pr.Next = l1
			break
		}
	}
	return head
}
```