### 解题思路
1. 遍历一次求length, 找到需要删除的位置
2. 遍历二次删除某个结点

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head is None or n == 0:
            return None

        _len, cur = 0, head
        while cur is not None:
            cur = cur.next
            _len += 1
        
        _no = _len - n
        # delete head
        if _no <= 0:
            head = head.next
        else:
            i, tempCur = 1, head
            while i < _no:
                tempCur = tempCur.next
                i += 1
            if n == 1:
                tempCur.next = None
            else:
                tempCur.next = tempCur.next.next
        return head
```