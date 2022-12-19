
双指针

```swift []
class Solution {
    func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
        var pre: ListNode?
        var cur: ListNode? = head
        var newHead: ListNode?
        while cur != nil {
            if cur?.val == val {
                cur = cur?.next
            } else {
                if newHead == nil {
                    newHead = cur
                    pre = cur
                } else {
                    pre?.next = cur
                    pre = cur
                }
                cur = cur?.next
            }
        }
        pre?.next = cur
        return newHead
    }
}
```

