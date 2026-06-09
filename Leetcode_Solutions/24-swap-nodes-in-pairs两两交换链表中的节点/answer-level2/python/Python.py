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
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None:
            return None
        newhead=ListNode(0)
        newhead.next=head
        pre=newhead
        while pre.next!=None and pre.next.next!=None  :
            l1=pre.next
            l2=pre.next.next
            next=l2.next
            l1.next=next
            l2.next=l1
            pre.next=l2


            pre=l1

        return newhead.next
```