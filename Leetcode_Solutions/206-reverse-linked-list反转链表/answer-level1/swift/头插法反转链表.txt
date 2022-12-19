### 解题思路
对于链表, 头插法就会得到输入顺序相反的链表. 
那么我们顺序遍历原链表, 头插法插入新的链表,则得到原链表的反转链表
使用dummy节点作为辅助可以简化代码

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
    func headInsert(_ head:ListNode?,node:ListNode?) {
        let tmp = head?.next
        head?.next = node
        node?.next = tmp
    }

    func reverseList(_ head: ListNode?) -> ListNode? {
        let dummy = ListNode(0)
        var currentNode = head

        while let node = currentNode {
            currentNode = currentNode?.next

            headInsert(dummy,node:node)
        }
        return dummy.next
    }
}
```