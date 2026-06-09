### 解题思路

按照题解，将链表划分成若干个小链表，每个小链表内的节点操作保持一致，设置head和next，于是可以尝试用递归实现

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
func swapPairs(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil {
            return head;
        }
        let next : ListNode? = head?.next
        head?.next = swapPairs(next?.next);
        next?.next = head;
        return next;
    }
}
```