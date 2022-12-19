### 解题思路
两个指针分别串奇偶，两个指针分别指示奇数头部（head）和偶数头部（原head.next，现为p3）.

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        p1, p2, p3 = head, head.next, head.next
        while p2 and p2.next:
            p1.next = p2.next
            p2.next = p2.next.next
            p1 = p1.next
            p2 = p2.next
        p1.next = p3
        return head
```