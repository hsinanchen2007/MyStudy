### 解题思路
遍历获取链表的中间节点，遍历过程中生成前半部分链表的反转链表

需要注意两点：
1、在swift中，ListNode是引用类型，生成前半部分的反转链表时一定要新建节点，而不是直接赋值：
`let newHead:ListNode? = ListNode(slow!.val)`
2、如果链表节点个数为奇数，fast指针在循环结束时不是nil，slow指针需要后移一位才是后半部分链表的起始位置

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
        guard head != nil else {
            return true
        }
        var slow = head
        var fast = head
        
        var reverseNode:ListNode? = nil
        
        while fast != nil && fast?.next != nil {
            let newHead:ListNode? = ListNode(slow!.val)
            slow = slow?.next
            fast = fast?.next?.next
            newHead?.next = reverseNode
            reverseNode = newHead
        }
        
        if fast != nil {
            slow = slow?.next
        }

        while reverseNode != nil && slow != nil {
            if reverseNode?.val != slow?.val {
                return false
            }
            reverseNode = reverseNode?.next
            slow = slow?.next
        }
        
        return true
    }
}
```