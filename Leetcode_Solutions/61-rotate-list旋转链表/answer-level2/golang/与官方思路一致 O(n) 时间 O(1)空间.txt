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
func rotateRight(head *ListNode, k int) *ListNode {
    //移动x，就是把后面的x个截取到前边
    //1. 找到倒数第k个节点
    //当前头是新的头，链表尾部链接原头;
	if head == nil || head.Next == nil {
		return head
	}
	//计算长度，k是否嵌套长度
	p:=head
	count := 0
	for ; p != nil ; p = p.Next{
		count++
	}
	//计算k有几个count
	nstep := k%count
	if nstep <= 0 {
		return head
	}
    pf := head
	ps := head
	for ;nstep > 0 && pf != nil ; nstep--{
		pf = pf.Next
	}

	for ;pf != nil && pf.Next != nil ; {
		ps = ps.Next
		pf = pf.Next
	}
	newHead := ps.Next
	ps.Next = nil
	pf.Next = head
	return newHead
}
```