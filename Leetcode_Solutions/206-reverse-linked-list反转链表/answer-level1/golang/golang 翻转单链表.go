为了读起来方便，没有在一行内复制。
```
func reverseList(head *ListNode) *ListNode {
	//pre := new(ListNode)	//pre不能声明为一个空值，那样会多增加一个节点
	var pre  *ListNode
	for head != nil {
		next := head.Next	//获取下一个需要遍历的node
		cur := head			//当前节点需要指向前一个节点
		cur.Next = pre
		pre = cur			//将pre节点指向当前节点
		head = next			//判断下一个节点
	}
	return pre
}
```
