### 解题思路

直接令给定节点的值等于下一节点的值，next指向下一节点的next

### 代码

```golang
func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}
```