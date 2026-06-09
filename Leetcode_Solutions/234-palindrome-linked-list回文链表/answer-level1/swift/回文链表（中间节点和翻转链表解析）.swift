### 解题思路
这一题的主要思路是寻找中间节点和反转链表。
#### 中间节点
* 首先，我们找到链表中的中间节点，链表是偶数个，那么中间节点是第n/2 + 1的那个节点。如果是奇数，那么中间节点就是第n / 2个。
* 我们应用快慢指针的方式,定义一快一慢的指针，快的指针运动的速度永远是慢的指针的两倍，也就是说慢指针是一个一个往后遍历，快的指针是两个两个的往后面遍历。如果是奇数个的链表，快指针遍历到最后一个的时候，慢指针正好是中间节点，如果是偶数个，在慢指针的next指针是最后一个的时候，中间节点正好是慢指针的next指针。
* 在得到中间节点之后，我们将中间节点的指针后面的这个链表翻转
* 翻转链表的话，我们可以创建一个新的链表，第一个指向nil，然后遍历这个需要翻转的链表，讲节点一个个加到新的链表的头上去。
* 最后同时遍历两个链表，这两个链表分别是翻转之后的链表和初始链表，只要有一个不为空的节点不相等，那么这个链表就不是回文链表，如果翻转后的链表已经指向了nil，并且没有不相同的节点，那么说明就是回文链表。


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
     func isPalindrome(_ head: ListNode?) -> Bool {
        if head?.next == nil {
            return true
        }
        if (head?.next?.next == nil) && head?.next?.val == head?.val {
            return true
        }
        var headNode = head
        
        let middleNode: ListNode? = getMiddleNode(head)
        var reverseNode: ListNode? = getReverseNode(middleNode)
        var isPalindrome = true
        while headNode != nil && reverseNode != nil {
            if headNode?.val != reverseNode?.val {
                isPalindrome = false
            }
            headNode = headNode?.next
            reverseNode = reverseNode?.next
        }
        
        return isPalindrome
    }
    ///翻转链表
    func getReverseNode(_ head: ListNode?) -> ListNode? {
        var curNode: ListNode? = nil
        var headNode = head
        while headNode != nil {
            let newNode: ListNode? = ListNode(headNode!.val)
            newNode?.next = curNode
            curNode = newNode
            headNode = headNode?.next
        }
        return curNode
    }
    ///获取中间节点
    func getMiddleNode(_ head: ListNode?) -> ListNode? {
        var slowNode = head
        var fastNode = head
        while slowNode?.next != nil && fastNode?.next?.next != nil  {
            slowNode = slowNode?.next
            fastNode = fastNode?.next?.next
        }
        if fastNode?.next != nil {
            return slowNode?.next
        }
        return slowNode
    }
}
```