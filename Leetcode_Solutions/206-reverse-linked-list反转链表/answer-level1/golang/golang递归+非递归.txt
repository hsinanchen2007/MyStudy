递归：
```
func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    newHead := reverseList(head.Next)
    head.Next.Next = head
    head.Next = nil
    return newHead
}
```
非递归：
```
func reverseList(head *ListNode) *ListNode {
    var pre  *ListNode
    var next *ListNode
    for head != nil {
        next = head.Next
        head.Next = pre
        pre = head
        head = next
    }
    return pre
}
```

