Go 递归解法

```
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {                 // 终止条件
		return head
	}
	firstNode := head
	secondNode := head.Next
	firstNode.Next = swapPairs(secondNode.Next)          // 调用递归
	secondNode.Next = firstNode
	return secondNode
}
```
