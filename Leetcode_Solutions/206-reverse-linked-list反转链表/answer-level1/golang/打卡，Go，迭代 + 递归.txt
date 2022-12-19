### 迭代思路

迭代解法稍微简单点, 只需额外设置3个变量分别用来保存当前节点, 上一个节点以及下一个节点即可.

### 迭代解法

```golang
func reverseList(head *ListNode) *ListNode {
	var pre, next *ListNode
	cur := head
	for cur != nil {
		next = cur.Next
		cur.Next, pre = pre, cur
		cur = next
	}
	return pre
}
```

### 迭代思路

迭代思路要抓住重点, 就是从后往前, 先做往尾部的逆序工作, 再回到头节点.

### 递归解法

```golang
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	p := reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil
	return p
}
```