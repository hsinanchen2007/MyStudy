### 解题思路
三个指针, 分别操作pre, cur, next, 不丢节点.

### 代码

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
    func reverseList(_ head: ListNode?) -> ListNode? {
        guard head != nil else {
            return head
        }
        guard head!.next != nil else {
            return head
        }
        var pre = head
        var cur = head!.next
        var next: ListNode?
        pre?.next = nil
        while cur != nil {
            next = cur!.next
            cur!.next = pre
            pre = cur
            cur = next
        }
        return pre
    }
}
```