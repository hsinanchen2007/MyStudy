
```
func getKthFromEnd(head *ListNode, k int) *ListNode {
    result := head
    for i:= 1; head != nil; i++ {
        if i > k {
            result = result.Next
        }
        head = head.Next
    }
    return result
}
```
