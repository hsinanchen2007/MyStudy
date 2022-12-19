### 解题思路

快慢指针，一次遍历

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
    func getKthFromEnd(_ head: ListNode?, _ k: Int) -> ListNode? {
        guard head != nil else { 
            return nil
        }
        var slow = head
        var fast = slow
        for _ in 1...k {
            fast = fast?.next
        }
        while fast != nil {
            fast = fast?.next
            slow = slow?.next
        }
        return slow
    }
}
```