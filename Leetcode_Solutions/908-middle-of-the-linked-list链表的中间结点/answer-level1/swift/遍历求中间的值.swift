### 解题思路
1.先遍历一遍链表，求出中间的值
2.然后在遍历到中间值，注意临界条件
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
 func middleNode(_ head: ListNode?) -> ListNode? {
    if head == nil {
        return head
    }
    
    var p = head
    var count = 0
    while p != nil {
        count += 1
        p = p?.next
    }
    let mid = count >> 1
    p = head
    for _ in 0 ..< mid {
        p = p?.next
    }
    return p
 }
}
```