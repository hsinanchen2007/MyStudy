### 解题思路
替换val，删除next节点

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
    if node == nil {
        return
    }
    node.Val = node.Next.Val
    node.Next = node.Next.Next
    return
}
```