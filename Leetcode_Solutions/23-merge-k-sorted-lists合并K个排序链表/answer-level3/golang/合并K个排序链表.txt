### 解题思路
两两合并

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
	if lists == nil || len(lists) == 0 {
		return nil
	}
	for len(lists) > 1 {
		li := make([]*ListNode, 0, (len(lists)+1)/2)
		l, r := 0, len(lists)-1
		for l < r {
			li = append(li, mergeTwoList(lists[l], lists[r]))
			l++
			r--
		}
		if l == r {
			li = append(li, lists[l])
		}
		lists = li
	}
	return lists[0]
}

func mergeTwoList(l1, l2 *ListNode) *ListNode {
	h := &ListNode{}
	p := h
	for l1 != nil || l2 != nil {
		if l1 == nil {
			p.Next = l2
			l2 = l2.Next
		} else if l2 == nil {
			p.Next = l1
			l1 = l1.Next
		} else {
			if l1.Val < l2.Val {
				p.Next = l1
				l1 = l1.Next
			} else {
				p.Next = l2
				l2 = l2.Next
			}
		}
		p = p.Next
	}
	return h.Next
}
```