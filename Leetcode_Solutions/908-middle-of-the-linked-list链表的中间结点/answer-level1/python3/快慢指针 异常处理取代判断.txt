利用异常处理机制简化一下处理，就这。
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        lst, mid = head, head
        try:
            while True:
                lst = lst.next.next
                mid = mid.next
        except Exception:
            return mid
```
