### 解题思路
![111.png](https://pic.leetcode-cn.com/fee7ab8cddd5d288dcfd737fb75cf9a387adabd7c2d193550b1c1e78eef3b7bd-111.png)

维护两个快慢指针 由于是有序的 所有
1.当碰到prev节点的值和cur节点值相同时 prev移动到当前位置cur上 cur节点继续向下移动
2.prev的值和cur节点值不同时 两个节点同时向后移动一个位置

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	var (
		h    = &ListNode{Val: 0, Next: head}
		prev = h
		cur  = h.Next.Next
	)

	for cur != nil {
		if prev.Next.Val == cur.Val {
			prev.Next.Next = nil
			prev.Next = cur
			cur = cur.Next
			continue
		}
		//p.Next.Val<cur.Val
		cur = cur.Next
		prev = prev.Next
	}
	return h.Next
}

```