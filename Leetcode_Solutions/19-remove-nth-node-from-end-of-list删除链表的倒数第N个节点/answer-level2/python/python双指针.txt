### 解题思路
双指针

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
        if head is None:
            return 
        cur = head
        length = 1
        while cur.next:
            length += 1
            cur = cur.next
        
        if length == n:
            head = head.next
            return head
        count = 1
        cur = head
        pre = cur
        while length-count+1 != n:
            count += 1
            pre = cur
            cur = cur.next
        pre.next = cur.next
        return head            
```