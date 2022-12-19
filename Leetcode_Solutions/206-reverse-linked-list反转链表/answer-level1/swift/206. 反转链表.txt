### 解题思路(迭代法)
1. 局部变量reversed存储反转后的链表
2. 由于Swift语法限制，入参默认是`let`修饰（不可更改），又不想加`inout`关键字（如果加了，调用的时候需要加`&`），所以申明了局部变量newHead
3. 每次循环反转一位，1-> nil, 2->1->nil, ...以此类推
4. 注意边界：链表为空或只有一个元素

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
    /// 迭代法
    func reverseList(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil { return head }
        var newHead = head
        var reversed: ListNode?
        while newHead != nil {
            let tmp = newHead?.next
            newHead?.next = reversed
            reversed = newHead
            newHead = tmp
        }
        return reversed
    }
    /// 递归法
    func reverseList(_ head: ListNode?) -> ListNode? {
        // 1 2 3 4 5  ->  5 4 3 2 1
        if head == nil || head?.next == nil { return head }
        let reversed = reverseList(head?.next) // 5 4 3 2   1
        // 反转之后，链表变成 5 4 3 2，此时只需要将2->1，并且1.next=nil即可
        // linkedList?.next: 2
        // 2.next = 1
        head?.next?.next = head
        head?.next = nil
        return reversed
    }
}
```