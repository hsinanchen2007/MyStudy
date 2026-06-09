时间复杂度： O(n)
空间复杂度： O(1)
```
 func removeNthFromEnd(head *ListNode, n int) *ListNode {
    slow, fast := head, head
    for n !=0 {
        fast = fast.Next
        n--
    }
    if fast == nil {
        return head.Next
    }
    for fast.Next !=nil {
        fast = fast.Next
        slow = slow.Next
    }
    slow.Next = slow.Next.Next
    return head
}
```
