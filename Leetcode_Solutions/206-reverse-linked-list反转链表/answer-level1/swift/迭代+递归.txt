### 解题思路
1. 迭代
    需要定义pre、cur两个指针，初始指向nil、head；接着遍历链表，在循环体内先用临时常量保存cur的next指针，然后将cur的next指向pre，实现指针翻转，    然后pre赋值为cur，cur赋值为临时常量nex，继续循环；最后输出pre，得到结果；时间复杂度为O(n)，空间复杂度为O(1)。
2. 递归
    首先先递归到尾结点，此时head为尾结点的上一结点，cur为尾结点，然后将head.next.next指向head，实现指针翻转，head.next指向nil以防止成环，最     后输出cur；时间复杂度为O(n)，空间复杂度为O(n)。（函数栈空间）
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
        //迭代
        if head == nil {
            return nil
        }
        var cur = head, pre: ListNode?
        while cur != nil {
            let nex = cur?.next
            cur?.next = pre
            pre = cur
            cur = nex
        }
        return pre

        //递归
        // if head == nil || head?.next == nil {
        //     return head
        // }
        // let cur = reverseList(head?.next)
        // head?.next?.next = head
        // head?.next = nil
        // return cur
    }
}
```