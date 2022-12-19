### 解题思路
此处撰写解题思路

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
    func mergeKLists(_ lists: [ListNode?]) -> ListNode? {
        if lists.count == 0 || lists.isEmpty {
            return nil
        }
        return merge(lists, 0, lists.count - 1)
    }
    func merge(_ list:[ListNode?],_ left:Int,_ right:Int) ->ListNode? {
        if left == right {
            return list[left]
        }
        let mid:Int = left + (right - left) / 2
        let l1:ListNode? = merge(list, left, mid)
        let l2:ListNode? = merge(list, mid + 1, right)
        return mergeTwoLists(l1,l2)
    }
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        var p:ListNode? = l1
        var q:ListNode? = l2
        let result:ListNode? = ListNode(-1)
        var prev:ListNode? = result
        
        while p != nil && q != nil {
            if (q?.val ?? 0) > (p?.val ?? 0) {
                prev?.next = p
                p = p?.next
            }
            else {
                prev?.next = q
                q = q?.next
            }
            prev = prev?.next
        }
        prev?.next = q == nil ? p : q
        return result?.next
    }
}
```