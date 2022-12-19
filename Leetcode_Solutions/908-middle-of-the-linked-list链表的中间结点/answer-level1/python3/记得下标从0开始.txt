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
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p=head
        i = 0
        while p:
            i= i+1
            p=p.next
        m=i/2
        p = head
        for j in range(m):
            p = p.next
        return p

            

```