```
// 递归版
func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil { return head }
    p := reverseList(head.Next)
    head.Next.Next = head
    head.Next = nil
    return p
}

// 迭代版
func reverseList(head *ListNode) *ListNode {
    var pre *ListNode
    for head != nil {
        after := head.Next
        head.Next = pre
        pre, head = head, after
    }
    return pre
}
```