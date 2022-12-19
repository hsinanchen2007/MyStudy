### 解题思路
定义一个空列表，每次遍历都将遍历的链表存入列表，再返回倒数第k个列表的值



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
        s = []
        while head :
            s.append(head)
            head = head.next
        return s[-k]
```