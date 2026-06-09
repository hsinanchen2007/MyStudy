### 代码

```python
# # Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def __init__(self):
        self.index=0

    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head.next:      
            node = self.removeNthFromEnd(head.next, n)
        else:
            node=None
        if not head.next:
            self.index+=1
        elif self.index:
            self.index+=1
        head.next=node
        if self.index==n:
            return head.next
        else:return head
        
        
        
            
```