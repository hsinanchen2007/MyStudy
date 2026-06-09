### 解题思路
遍历链表把数字输入到数组中，数组倒序
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
    func reversePrint(_ head: ListNode?) -> [Int] {
        var node = head
        var queue:[Int] = []
        while node != nil {
            if let val = node?.val {
                queue.append(val)
            }
            node = node?.next
        }
        return queue.reversed()
    }
}
```