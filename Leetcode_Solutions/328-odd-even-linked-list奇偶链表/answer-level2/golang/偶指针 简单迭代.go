### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if nil == head {
        return head
    }
    p1, p2 := head, head.Next
    for nil != p2 && nil != p2.Next {
        t := p1.Next
        p1.Next = p2.Next
        p2.Next = p2.Next.Next
        p1.Next.Next = t
        p1 = p1.Next
        p2 = p2.Next
    }
    return head
}
```