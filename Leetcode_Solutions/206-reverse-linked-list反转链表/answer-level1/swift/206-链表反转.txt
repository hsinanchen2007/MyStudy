### 解题思路
迭代
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

        if head == nil {
            return nil
        }
        var cur: ListNode? = head
        var pre: ListNode?
        var next: ListNode?
        while(cur != nil) {
            next = cur?.next
            cur?.next = pre
            pre = cur
            cur = next
        }
        return pre
    }
}
```