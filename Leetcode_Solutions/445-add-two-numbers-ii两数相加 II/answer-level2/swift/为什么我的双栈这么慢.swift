### 解题思路

感觉这个双栈也没啥特殊的吧，反转链表时的要求是不要借助其他数据结构，现在借助栈反倒是进阶方法了，不太明白

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
func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
    var stack1 = [ListNode]()
    var stack2 = [ListNode]()
    
    var t1 = l1
    var t2 = l2
    
    while t1 != nil || t2 != nil {
        if let tmpT1 = t1 {
            stack1.append(tmpT1)
            t1 = t1?.next
        }
        
        if let tmpT2 = t2 {
            stack2.append(tmpT2)
            t2 = t2?.next
        }
    }
    
    var newHead: ListNode?
    var k = 0
    while !stack1.isEmpty || !stack2.isEmpty || k != 0 {
        var sum = k
        k = 0
        if !stack1.isEmpty {
            sum += stack1.removeLast().val
        }
        
        if !stack2.isEmpty {
            sum += stack2.removeLast().val
        }
        
        if sum > 9 {
            sum -= 10
            k = 1
        }
        let node = ListNode(sum)
        if newHead == nil {
            newHead = node
        } else {
            node.next = newHead
            newHead = node
        }
    }
    return newHead
}
}
```