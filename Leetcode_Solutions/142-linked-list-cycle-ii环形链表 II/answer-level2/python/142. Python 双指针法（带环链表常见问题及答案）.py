### 解题思路
链表带环问题的通用解决方法：双指针法，一个速度为1，一个速度为2.
（1）链表是否带环：判断是否能相遇或者到达None；
（2）判断环长：相遇之后快慢指针再走一轮，记录慢指针的步数即为环长；
（3）判断柄长（环的入口位置）：相遇之后两个速度为1的指针，一个从head走，一个从相遇位置走，汇合位置即为入口。

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
        p = q = head
        while q and q.next:
            p = p.next
            q = q.next.next
            if p == q:
                p = head
                while p != q:
                    q = q.next
                    p = p.next
                return p
        return None

```