```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        jishu = ListNode(0)
        jishu1 = jishu
        oushu = ListNode(0)
        oushu1 = oushu
        n2 = 1
        while head != None:
            if n2 % 2 == 1:
                jishu1.next = ListNode(head.val)
                jishu1 = jishu1.next
            elif n2 % 2 == 0:
                oushu1.next = ListNode(head.val)
                oushu1 = oushu1.next
            head = head.next
            n2 += 1
        jishu = jishu.next
        oushu = oushu.next
        jishu1.next = oushu
        return(jishu)
```
