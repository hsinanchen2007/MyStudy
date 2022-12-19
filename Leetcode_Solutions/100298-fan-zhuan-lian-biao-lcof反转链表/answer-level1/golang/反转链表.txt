### 解题思路
递归反转

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    if head.Next == nil {
        return head
    }
    p := reverseList(head.Next)
    q := p
    for q.Next != nil {
        q = q.Next
    }
    q.Next = head
    head.Next = nil
    return p
}
```