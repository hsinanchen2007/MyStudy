
三指针法，中间指针为有效值

```swift []
class Solution {
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
    
        if head?.next == nil {
            return head
        }
        
        var newHead: ListNode?
        var newCur: ListNode?
        
        
        var pre: ListNode?
        var now: ListNode? = head
        var next: ListNode? = head?.next
        
        while now != nil {
            if pre?.val != now?.val, now?.val != next?.val {
                if newHead == nil {
                    newHead = now
                    newCur = now
                } else {
                    newCur?.next = now
                    newCur = now
                }
            }
            pre = now
            now = next
            next = now?.next
        }
        newCur?.next = now
        return newHead
    }
}
```

