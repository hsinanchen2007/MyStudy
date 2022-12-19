### 解题思路
双指针法不需过多解释，这里给出一点建议，只要有对链表进行添加或者删除操作，使用虚拟头结点会使问题简单很多。

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
        v_head = ListNode(0)
        temp = v_head
        p, q = l1, l2
        while p or q:
            if p and (q is None or p.val < q.val):
                temp.next = ListNode(p.val)
                p = p.next
            else:
                temp.next = ListNode(q.val)
                q = q.next
            temp = temp.next
        return v_head.next
```