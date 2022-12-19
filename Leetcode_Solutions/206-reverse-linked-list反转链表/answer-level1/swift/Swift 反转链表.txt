### 解题思路

基本操作断链、移位即可，需注意在日常撸代码中尽量使用非递归算法

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
    //    func reverseList(_ head: ListNode?) -> ListNode? {
//
//        if head == nil || head?.next == nil {
//            return head
//        }
//
//        var p1, p2, p3: ListNode?
//        p1 = head
//        p2 = p1?.next
//        p3 = p2?.next
//
//        while p2 != nil {
//            p3 = p2?.next
//            p2?.next = p1
//
//            p1 = p2
//            p2 = p3
//        }
//
//        head?.next = nil
//        return p1
//    }
    
    func reverseList(_ head: ListNode?) -> ListNode? {
        
        if head == nil || head?.next == nil {
            return head
        }
        
        let newHead = reverseList(head?.next)
        head?.next?.next = head
        head?.next = nil
        return newHead
    }
}
```