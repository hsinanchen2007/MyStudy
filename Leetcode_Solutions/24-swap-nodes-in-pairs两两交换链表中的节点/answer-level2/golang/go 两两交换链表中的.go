```
func swapPairs(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	h := &ListNode{0, head}
	pre := h
	cur := h.Next
	for cur != nil && cur.Next != nil {
		pre.Next = cur.Next
		cur.Next = cur.Next.Next
		pre.Next.Next = cur
		pre = cur
		cur = cur.Next
	}
	return h.Next
}
```
![image.png](https://pic.leetcode-cn.com/00c7d98985f82a45897ddfe3307dac25310728426abd54f0140eaf7688c740f0-image.png)

step1: 移动pre 指针，指向当前节点的下一个节点
step2: 改变当前节点的next指向，指向cur.next.next
step3: 改变pre节点的next指向，指向当前节点
step4: 经过1-3，next指针的变动已经完成，将pre指针指向当前的cur
step5：将cur指向cur.next。
开始下一次循环。