### 解题思路
用列表存储，然后反转列表

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
        l = []
        while head:
            l.append(head.val)
            head = head.next
        l = l[::-1]
        if len(l)>0:
            new = ListNode(l[0])
            rnew = new
            for i in range(1,len(l)):
                new.next = ListNode(l[i])
                new = new.next
            return rnew
        else:
            return []
```