将奇节点放在一个链表里，偶链表放在另一个链表里，然后将奇数链表的尾指针指向偶数链表的头指
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        o = head.next
        j = head
        tem1 = j
        tem2 = o
        while o and j and o.next:
            j.next = o.next
            j = j.next
            o.next = j.next
            o = o.next
        j.next = tem2
        return tem1
            
            
        
            
```