### 解题思路
1、基本思路就是双指针；
2、先让第一个指针走K步，然后俩指针同时走，第一个指针走到末尾，第二个指针就是第K个节点；

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getKthFromEnd(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        low=head
        fast=head
        for _ in range(k):
            fast = fast.next
        
        while fast:
            low=low.next
            fast=fast.next
        return low
```