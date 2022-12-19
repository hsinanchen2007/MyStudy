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
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None:
            return None
        odd=head
        even=head.next
        evenhead=even
        while even!=None and even.next!=None:
            odd.next=odd.next.next

            odd=odd.next
            even.next=even.next.next
            even=even.next
        odd.next=evenhead
        return head
```