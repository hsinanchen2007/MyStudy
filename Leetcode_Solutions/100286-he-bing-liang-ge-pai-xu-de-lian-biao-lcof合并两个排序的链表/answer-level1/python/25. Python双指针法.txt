### 解题思路
双指针法很简单，不再赘述，只想再提醒一下，只要有对链表的修改操作，考虑添加虚拟头结点能够使问题变简单。

### 代码

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
        p = l1
        q = l2
        v_head = ListNode(0)
        t = v_head
        while p or q:
            if q is None or p and p.val <= q.val:
                t.next = p
                p = p.next
            else:
                t.next = q
                q = q.next
            t = t.next
        return v_head.next

```