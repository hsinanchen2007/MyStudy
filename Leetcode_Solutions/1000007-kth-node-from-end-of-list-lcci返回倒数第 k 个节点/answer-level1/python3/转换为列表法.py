### 解题思路
将链表转换成列表求解，可能违背了出题者的本意。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def kthToLast(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: int
        """
        list1 = []
        while head:
            list1.append(head.val)
            head = head.next
        n = len(list1)
        return list1[n-k]        
```