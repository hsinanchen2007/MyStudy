### 解题思路

插头法

### 代码

```golang
func reverseList(head *ListNode) *ListNode {
	var newHead *ListNode
	for head != nil {
		var next = head.Next //保留下一个节点
		head.Next = newHead  //开始转移
		newHead = head       //重新标记节点
		head = next          //循环下一个
	}
	return newHead
}
```