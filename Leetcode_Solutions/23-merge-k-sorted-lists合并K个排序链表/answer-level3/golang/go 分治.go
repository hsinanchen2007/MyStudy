### 解题思路
采用分治的方式

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
	length := len(lists)
    if length == 0 {
		return nil
	}
    if length == 1 {
		return lists[0]
	}
	return merge(lists, 0, length-1)
}

func merge(lists []*ListNode, left int, right int) *ListNode{
	if left == right {
		return lists[left]
	}
	mid := left + (right - left)/2
	l1 := merge(lists, left, mid)
	l2 := merge(lists, mid+1, right)
	return mergeTwoLists(l1, l2)
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var head *ListNode
	var p, q *ListNode
	if l1 == nil && l2 == nil {
		return nil
	}
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	for {
		if l1 != nil && l2 != nil {
			if l1.Val < l2.Val {
				p = l1
				l1 = l1.Next
			} else {
				p = l2
				l2 = l2.Next
			}
			if q == nil {
				q = p
			} else {
				q.Next = p
				q = q.Next
			}
			if head == nil {
				head = p
			}
		} else if l1 != nil {
			p.Next = l1
			break
		} else if l2 != nil {
			p.Next = l2
			break
		} else {
			break
		}
	}
	return head
}
```