### 解题思路
此处撰写解题思路

迭代方法，pre, cur.next = cur, pre

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
        tmp, pre, cur = None, None, head
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
            
        return pre
            
```