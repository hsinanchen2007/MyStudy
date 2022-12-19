### 解题思路
遍历，按值分割成两个子链表，再合并

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	sh := &ListNode{}
	bh := &ListNode{}
	sp := sh
	bp := bh
	p := head
	for p!=nil {
		if p.Val < x {
			sp.Next = p
			sp = sp.Next
		}else {
			bp.Next = p
			bp = bp.Next
		}
		p = p.Next
	}
	bp.Next = nil
	sp.Next = bh.Next
	return sh.Next
}

```