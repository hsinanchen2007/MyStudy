### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        new_head = None

        while head is not None:
            temp = head.next
            head.next = new_head
            new_head = head
            head = temp
        
        return new_head
```