```swift
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func removeElements(_ head: ListNode?, _ val: Int) -> ListNode? {
        var now = head
        while now != nil {
            var next = now?.next
            while next?.val == val {
                next = next?.next
            }
            now?.next = next
            now = now?.next
        }
        if head?.val == val {
            return head?.next
        }
        return head
    }
}
```