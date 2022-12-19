### 解题思路
遍历入栈，然后出栈的时候相加生成新的链表

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
        func nodeList(_ node: ListNode?) -> [ListNode] {
            /// 用数组模拟栈结构
            var nodeList = [ListNode]()
            var tmpNode = node
            while let listNode = tmpNode {
                nodeList.append(listNode)
                tmpNode = tmpNode?.next
            }
            
            return nodeList
        }
        
        /// 用数组模拟栈结构
        var nodeList1 = nodeList(l1)
        var nodeList2 = nodeList(l2)
        var result: ListNode?
        var shouldCarry = 0
        while !nodeList1.isEmpty || !nodeList2.isEmpty {
            var first = 0
            var second = 0
            if let node = nodeList1.last {
                first = node.val
            }
            if let node = nodeList2.last {
                second = node.val
            }
            let sum = first + second + shouldCarry
            let node = ListNode(sum % 10)
            shouldCarry = sum / 10
            node.next = result
            result = node
            
            nodeList1 = nodeList1.dropLast()
            nodeList2 = nodeList2.dropLast()
        }
        
        if shouldCarry > 0 {
            let node = ListNode(shouldCarry)
            node.next = result
            result = node
        }
        
        return result
    }
}
```