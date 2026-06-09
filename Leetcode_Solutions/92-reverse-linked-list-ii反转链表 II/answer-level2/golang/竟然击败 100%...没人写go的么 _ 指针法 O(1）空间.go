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
func reverseBetween(head *ListNode, m int, n int) *ListNode {
    	if head == nil || m >=n {
		return head
	}
	pHeadMark := head
	pPreMark := head
	pPreMark = nil
	for i:=1; i < m && head != nil ; i++{
		pPreMark = head
		head = head.Next
	}

	//m 大于 head 长度
	if head == nil {
		return head
	}
	cur := head
	pPre := &ListNode{0, nil }
	pPre = nil
	next := head.Next
	pEndMark := cur
	for i := m ;next != nil && i < n ; i++{
		cur.Next = pPre
		pPre = cur
		cur = next
		next = next.Next
	}

	cur.Next = pPre

	if pPreMark != nil {
		pPreMark.Next = cur
	}else{
		//从首节点开始换，转换连表的头为新的头;
		pHeadMark = cur
	}

	pEndMark.Next = next
	return pHeadMark
}
```