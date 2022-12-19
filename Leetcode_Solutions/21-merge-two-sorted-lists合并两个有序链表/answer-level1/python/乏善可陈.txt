乏善可陈。

整道题目的代码如下：

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None and l2 is None:
            return None
        if l1 is None and l2 is not None:
            return l2
        if l1 is not None and l2 is None:
            return l1

        res = ListNode(0)
        temp = res
        cur = res
        while l1 and l2:
            if l1.val < l2.val:
                temp.val = l1.val
                l1 = l1.next
            else:
                temp.val = l2.val
                l2 = l2.next
            cur = temp
            temp.next = ListNode(0)
            temp = temp.next

        if l1:
            cur.next = l1
        elif l2:
            cur.next = l2
        else:
            cur.next = None

        return res
```

