### 解题思路
采用官方所说解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	if k <= 0 {
		return head
	}

	var (
		h   = &ListNode{Val: 0, Next: head}
		p   = h.Next
		cur = h.Next
		n   = 1
	)

	//移动到末尾
	for ; cur.Next != nil; n++ {
		cur = cur.Next
	}

	//最后一个结点指向头节点构成环
	cur.Next = p
	
	//计算分割点
	split := k % n
	
	//找到分割点的前一个位置
	for i := 0; i < n-split-1; i++ {
		p = p.Next
	}

	//更新头指针
	h.Next = p.Next
	//尾指针指向空
	p.Next = nil

	return h.Next
}
```