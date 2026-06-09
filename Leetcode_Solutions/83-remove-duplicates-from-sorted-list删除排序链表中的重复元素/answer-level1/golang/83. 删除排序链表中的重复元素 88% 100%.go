### 解题思路
算法：充分利用排序特性，如果重复则肯定是前后节点关系，直接顺序比较。如果重复则即就地删除节点，否则更新前置节点。

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	//直接从第二个节点开始比较
	var node, pre = head.Next, head
	for node != nil {
		if node.Val == pre.Val {
			pre.Next = node.Next
		} else {
			//仅当不重复时，pre重置为当前节点
			pre = node
		}
		node = node.Next
	}
	return head
}
```