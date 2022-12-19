### 解题思路
此处撰写解题思路

使用三个指针：
cur：游标，记录当前遍历到的节点
prev：记录cur的上一个节点，以便能够实现 cur.next = prev 反转逻辑
next：记录cur的下一个节点，以便cur.next = prev之后，cur能够继续向下遍历

递归法 （考虑方法作用）
func reverseList(_ head: ListNode?) -> ListNode? {
        // 递归基
        if (head == nil || head?.next == nil) {
            return head
        }

        // reverseList函数作用
        // 1 -> [2 -> 3 -> 4 -> 5 -> nil] ==> 1 -> [nil <- 2 <- 3 <- 4 <- 5]
        // 再执行：1 <-> [nil <- 2 <- 3 <- 4 <- 5]
        // 最后再清掉尾指针，防止循环出现
        let newHead = reverseList(head?.next) // 先反转后边部分
        // newHead为反转后链表的头部，直接返回
        // 经过这个函数，head.next就变成了反转后链表的尾巴，我们再将改尾巴接上当前head，清掉head.next完成了本次链表的反转。如此不断递归
        head?.next?.next = head
        head?.next = nil
        return newHead
}

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
        if (head == nil || head?.next == nil) {
            return head
        }
        
        var prev: ListNode? = nil
        var cur = head
        var next = cur?.next
        
        while cur != nil {
            cur?.next = prev
            prev = cur
            cur = next
            next = next?.next
        }
        return prev
    }
}
```