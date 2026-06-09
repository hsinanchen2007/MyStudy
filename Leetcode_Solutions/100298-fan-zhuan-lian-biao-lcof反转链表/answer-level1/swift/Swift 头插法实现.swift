### 解题思路

#### 迭代实现

1. 创建新头结点 newH
2. 迭代链表直到最后一个节点
3. 每次迭代都执行几步固定的操作
    1. 保存当前节点head的下一节点 head.next(tmp = head.next 为了后面使用时候不会断掉)
    2. 将当前节点head的next 执行新头结点newH（head.next = newH 反转，当然是原来前驱变成现在的后继）
    3. 将新头节点newH 指向当前head (newH = head 步进啊)
    4. 将head 节点指向temp 节点（head = tmp, 步进啊）

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
    func reverseList(_ head: ListNode?) -> ListNode? {
        
        var head = head
        var newH:ListNode?

        while head != nil {
            let tmp = head?.next
            head?.next = newH
            newH = head
            head = tmp
        }
        
        return newH
    }
}
```