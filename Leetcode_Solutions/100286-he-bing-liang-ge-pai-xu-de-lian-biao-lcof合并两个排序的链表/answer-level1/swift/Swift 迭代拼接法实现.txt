### 解题思路

按最短的链表遍历，小的节点拼到新链表尾部，步进1，一直执行到短链表末端
将剩下的长链表剩余节点拼接到新链表尾部即可

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
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var l1 = l1
        var l2 = l2
        let head:ListNode = ListNode(-1)
        var cour:ListNode? = head
        while l1 != nil && l2 != nil {
            if l1!.val < l2!.val {
                cour?.next = l1
                l1 = l1?.next
            } else {
                cour?.next = l2
                l2 = l2?.next
            }
            cour = cour?.next
        }
        
        cour?.next = l1 != nil ? l1 : l2
        
        return head.next
    }
}
```