### 解题思路
此题主要是创建两个新的链表，一个存放小于x的节点，一个存放大于等于x的节点，然后将两个链表拼接成一个链表就形成了结果。
如果是有多个特定值的话，就相应创建多个链表，每个链表存放相应的分隔的节点。最后按照一定的顺序拼接好链表就行。

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
    func partition(_ head: ListNode?, _ x: Int) -> ListNode? {
        var optHeadNode = head
        
        let minNode = ListNode(0)
        var optMinNode = minNode
        
        let maxNode = ListNode(0)
        var optMaxNode = maxNode
        
        while optHeadNode != nil {
            if optHeadNode!.val >= x {
                optMaxNode.next = optHeadNode
                optMaxNode = optMaxNode.next!
            } else {
                optMinNode.next = optHeadNode
                optMinNode = optMinNode.next!
            }
            optHeadNode = optHeadNode?.next
        }
        optMaxNode.next = nil
        optMinNode.next = maxNode.next
        return minNode.next
    }
}
```