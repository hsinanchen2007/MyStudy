```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        ret = head
        if head == None:
            return ret
        while head.next != None:
            while head.next.val == head.val:
                if head.next.next != None:
                    head.next = head.next.next
                else:
                    head.next = None
                    return ret
                temp = head.val
            head = head.next
        return ret
```
链表操作练习。中间需要用while循环