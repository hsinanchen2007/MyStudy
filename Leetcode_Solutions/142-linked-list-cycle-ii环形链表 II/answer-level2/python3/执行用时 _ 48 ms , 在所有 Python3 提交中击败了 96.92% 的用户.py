### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head == None:
            return None

        if head.next == None:
            return None

        if head.next == head:
            return head
        fast = head.next.next
        slow = head.next

        
        while fast != slow and fast != None and slow != None and fast.next != None and fast.next.next != None and slow.next != None:

            fast = fast.next.next
            slow = slow.next
        
        if fast != slow:
            return None
        
        fast = head

        while fast != slow:
            fast = fast.next
            slow = slow.next
        
        return fast
        
```