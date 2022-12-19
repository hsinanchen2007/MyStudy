节点交换的思路很简单，希望代码能够让你容易理解整个过程。

我更想将在解题过程中的思考展示出来抛砖引玉。
1. dumb指向end改为指向end.next是否可以？
    答案是否定的。
    一：因为dumb是哨指针的引用，dumb的next改变会直接导致哨指针后续链表循序的改变。
    二：dumb.next指向end.next导致第一个循环中的start和end节点都会被漏掉，并且之后每个循环都会有一个节点被漏掉。

2. 三个引用（dumb，start，end）改为两个引用是否可以？
    答案是否定的；
    首先每个循环中dumb.next都只能指向end，事实上也只能指向end。如果只保留一个start，那么少的指针指向的节点只能用dumb.next或者start.next，dumb.next肯定是无法改变的，那只能改变start.next。但是start.next的改变和start.next.next的改变是一致的，改了一个另一个也会被改变。所以三个引用是必须的。

```swift []
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
        let  head_ = ListNode.init(-1)
        head_.next = head
        var dumb: ListNode? = head_
        while dumb?.next != nil, dumb?.next?.next != nil {
            let firstNode = dumb?.next
            let secondNode = dumb?.next?.next
            dumb?.next = secondNode
            firstNode?.next = secondNode?.next
            secondNode?.next = firstNode
            dumb = firstNode
        }
        return head_.next
    }
}
```
```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        head_ = ListNode(-1)
        head_.next = head
        dumbNode = head_
        while dumbNode.next is not None and dumbNode.next.next is not None:
            firstNode = dumbNode.next
            secondNode = dumbNode.next.next
            dumbNode.next = secondNode
            firstNode.next = secondNode.next
            secondNode.next = firstNode
            dumbNode = firstNode
        return head_.next
```
