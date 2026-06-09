题目说出了“旋转”的关键字，其实指明了解题的思路之一：
1，将链表头尾连接形成环
2，旋转后游标指向某个位置
3，保存头，断开链表

重点在于第二步，旋转多少次，一眼看会以为是k%length，但实际上，想象旋转的时候，其实游标是不动的，动的是链表本身，
就像一个分针永远指向正上方的时钟，我们顺时针旋转表盘本身，刻度一个一个滑过分针，最后分针指向某个数字，所以旋转的次数是 k = length - (k % length)

```
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil || k == 0 {
		return head
	}
	var cur *ListNode
	var chead *ListNode
	length := 1

	cur = head
	//遍历得到长度，对K取模
	for cur.Next != nil {
		cur = cur.Next
		length ++
	}
	//旋转次数
	k = length - (k % length)
	//连成环
	cur.Next = head
	cur = head

	for i:=1;i<k;i++{
		//pre = cur
		cur = cur.Next
	}
	//旋转到定位后断开
	chead = cur.Next
	cur.Next = nil

	return chead
}
```
