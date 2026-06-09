### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fast=head
        while(fast!=None and n!=0):
            fast=fast.next
            n=n-1
        if fast==None:
            return head.next
        slow=head
        while(fast.next!=None):
            
            fast=fast.next
            slow=slow.next
        
        slow.next=slow.next.next
        return head
```