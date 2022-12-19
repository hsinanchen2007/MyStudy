注意不要忽略为空的情况！
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        tail = head
        if tail == None:
            return head
        while tail.next != None:
            if tail.val == tail.next.val:
                tail.next = tail.next.next
            else:
                tail = tail.next
        return head
```