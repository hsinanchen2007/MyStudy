### 解题思路
自底向上进行归并操作.

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
	n := 0
	p := head
	for p != nil {
		n++
		p = p.Next
	}
	h := &ListNode{}
	h.Next = head

	// 自底向上分段归并
	for sz := 1; sz < n; sz *= 2 {
		lprev := h
		for lprev.Next != nil {
			rprev := lprev
			tail := lprev
			for i := 0; rprev.Next != nil && i < sz; i++ {
				rprev = rprev.Next
				if tail != nil && tail.Next != nil {
					tail = tail.Next.Next
				}
			}
			lhead := lprev.Next
			rhead := rprev.Next

			// 断开该段的左,右子链表
			rprev.Next = nil

			// 维护下一段起始节点
			var nextLhead *ListNode = nil
			if tail != nil {
				nextLhead = tail.Next
				// 断开当前段与下一段的连接
				tail.Next = nil
			}
			// 对当前段进行归并操作
			lprev.Next, lprev = mergeList(lhead, rhead)
			// 更新lprev,继续进行下一段的合并
			lprev.Next = nextLhead
		}
	}
	return h.Next
}

func mergeList(l, r *ListNode) (*ListNode, *ListNode) {
	h := &ListNode{}
	p := h
	for l != nil && r != nil {
		if l.Val <= r.Val {
			p.Next = l
			l = l.Next
		} else {
			p.Next = r
			r = r.Next
		}
		p = p.Next
	}
	for l != nil {
		p.Next = l
		l = l.Next
		p = p.Next
	}
	for r != nil {
		p.Next = r
		r = r.Next
		p = p.Next
	}
	return h.Next, p
}

```