### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    h := head
    for head != nil && head.Next != nil {
        h = h.Next
        head = head.Next.Next
    }

    return h
}
```