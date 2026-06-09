```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        pre = dummy     
        for _ in range(m-1):
            pre = pre.next

        node = pre
        cur = pre.next
        
        for _ in range(n-m+1):
            cur.next, cur, pre = pre, cur.next, cur
        
        node.next.next = cur
        node.next = pre
        
        return dummy.next
```
