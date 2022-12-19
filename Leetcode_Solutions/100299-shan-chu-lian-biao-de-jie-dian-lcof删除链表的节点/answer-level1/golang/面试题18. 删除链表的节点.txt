### 解题思路
需要考虑几种场景
1. 删除节点是头结点
2. 删除节点是中间节点
3. 删除节点是尾节点

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(head *ListNode, val int) *ListNode {
	if head == nil {
		return head
	}
	node := head
	// 头结点
	if head.Val == val{
		head = head.Next
		return head
	}
	for node.Next != nil {
		if node.Next.Val == val {
			// 尾节点
			if node.Next.Next == nil {
				node.Next = nil
                return head
			}
			// 非尾节点
			node.Next = node.Next.Next
		}
		node = node.Next
	}
	return head

}
```
