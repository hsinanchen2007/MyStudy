```
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = head = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                head.next = ListNode(l1.val)
                l1 = l1.next
                head = head.next
            elif l1.val > l2.val:
                head.next = ListNode(l2.val)
                head = head.next
                l2 = l2.next
            else:
                head.next = ListNode(l1.val)
                head = head.next
                head.next = ListNode(l1.val)
                head = head.next
                l1 = l1.next
                l2 = l2.next
        if l1:
            head.next = l1
        if l2:
            head.next = l2
        
        return res.next
```
