```go
func insertionSortList(head *ListNode) *ListNode {
    dummy := &ListNode{}
    for head != nil {
        curr := dummy
        next := head.Next
        for curr.Next != nil && curr.Next.Val < head.Val {
            curr = curr.Next
        }

        head.Next = curr.Next
        curr.Next = head
        head = next
    }
    return dummy.Next
}
```
