1. 找打新链表的头
2. 将原链表尾指向原链表头（成环）
3. 将新头的上一个节点指向NULL
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:return head
        count = 0
        cur = head
        while cur:
            count += 1
            cur = cur.next
        if k % count == 0: return head

        steps = k % count
        pre_count = count - steps

        break_point = head
        while pre_count > 0:
            break_point = break_point.next
            pre_count -= 1
        
        cur = break_point
        while cur.next:
            cur = cur.next
        cur.next = head
        while cur.next != break_point:
            cur = cur.next
        cur.next = None
        return break_point
```
