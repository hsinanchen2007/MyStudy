### 解题思路
先把下一个结点的值复制到当前结点，然后将下一个结点删除即可。

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
    // 先把下一个结点的值复制到当前结点，
    // 然后将下一个结点删除即可
    if node == nil || node.Next==nil {
        return
    }
    node.Val = node.Next.Val
    tmp := node.Next.Next
    node.Next.Next = nil
    node.Next = tmp
}
```