### 解题思路
`核心代码 next = head.next head.next = pre pre = head head = next`

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
        pre = None
        while head != None:
            next = head.next
            head.next = pre
            pre = head
            head = next
        return pre
```