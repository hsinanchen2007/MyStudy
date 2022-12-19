```
class Solution {
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
    var current = head
    var nextPointer = head?.next
    current?.next = nil
    while nextPointer != nil {
        if current?.val == nextPointer?.val {
            nextPointer = nextPointer?.next
        } else {
            current?.next = nextPointer
            current = current?.next
            nextPointer = current?.next
            current?.next = nil
        }
    }
    return head
}
}
```
