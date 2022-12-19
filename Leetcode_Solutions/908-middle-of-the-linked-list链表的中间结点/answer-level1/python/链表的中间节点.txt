### 解题思路
第一次没看答案做出来的

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
        if head == None:
            return None
        list = []
        while head:
            list.append(head)
            head = head.next
        if len(list) // 2 != int(len(list) / 2):
            return list[len(list) // 2 -1]
        else:
            return list[len(list) // 2]
            
```