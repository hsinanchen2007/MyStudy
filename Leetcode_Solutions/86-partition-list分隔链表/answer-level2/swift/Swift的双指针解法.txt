# 思路
1. 在链表中找到第一个大于等于x的节点p
2. 在p节点后方找到小于x的节点q，删除q
3. 将q插入到p之前

```swift
class Solution {
    func partition(_ head: ListNode?, _ x: Int) -> ListNode? {
        if head == nil || head?.next == nil { return head }
        let dummy = ListNode(-1)
        dummy.next = head
        var p = head
        var preInsert: ListNode? = dummy
        while let node = p, node.val < x {
            preInsert = p
            p = p?.next
        }

        var cur = preInsert
        while cur?.next != nil {
            if cur!.next!.val < x {
                // 被删除的节点
                let deleted = cur?.next
                // 删除小于x的节点
                cur?.next = cur?.next?.next
                // 将删除节点插入
                deleted?.next = preInsert?.next
                preInsert?.next = deleted
                // 保证两个分区中每个节点的初始相对位置
                preInsert = deleted
            } else {
                cur = cur?.next
            }
        }

        return dummy.next
    }
}

```
