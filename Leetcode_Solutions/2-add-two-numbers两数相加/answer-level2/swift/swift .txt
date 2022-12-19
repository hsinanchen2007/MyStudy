# 思路
从个位数加起，注意进位
```
        p1
l1:     2-> 3-> 4
l2:     4-> 5-> 6
        p2

head->  6-> 8-> 0-> 1
        p3
```
```
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        guard l1 != nil || l2 != nil else {
            return nil
        }
        let head = ListNode(0)
        var p1 = l1
        var p2 = l2
        var p3 = head
        var carry = 0
        while p1 != nil || p2 != nil || carry == 1{
            let val = (p1?.val ?? 0) + (p2?.val ?? 0) + carry
            p3.next = ListNode(val % 10)
            carry = val >= 10 ? 1 : 0
            p1 = p1?.next
            p2 = p2?.next
            p3 = p3.next!
        }
        return head.next
    }
}
```
