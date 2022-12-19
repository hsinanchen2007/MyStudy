```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = curr = ListNode(-1)
        flag = 0
        while l1 or l2:
            v1 = 0 if l1 is None else l1.val
            v2 = 0 if l2 is None else l2.val

            v = (v1 + v2 + flag) % 10
            flag = (v1 + v2 + flag) // 10

            curr.next = ListNode(v)
            curr = curr.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        curr.next = ListNode(flag) if flag else None
        return res.next
```
