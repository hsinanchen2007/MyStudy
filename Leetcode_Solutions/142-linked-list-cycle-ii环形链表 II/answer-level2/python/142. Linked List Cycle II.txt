### 解题思路
同141 那道题，简单

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pos, _dict = 0, {}

        if head is None:
            return None
        while head is not None:
            if head in _dict:
                return head
            # 位置存入
            _dict[head] = pos
            head = head.next
            pos += 1
        return head
```