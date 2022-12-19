### 解题思路

书上解法：直接将后继节点的数据复制到当前节点，然后删除这个后继节点。  

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteNode(node *ListNode) {
    next := node.Next
    node.Val = next.Val
    node.Next = next.Next
}
```