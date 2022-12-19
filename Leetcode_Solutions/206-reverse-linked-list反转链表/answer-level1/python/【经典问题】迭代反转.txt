### 解题思路
非常经典的链表问题，大致思路就是通过制造一个pre的空指针，然后让cur指针不断的反向指向pre，实现局部反转，通过迭代的方式进行整个链表的反转。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre=None
        cur=head
        while cur:
            third=cur.next
            cur.next=pre
            pre=cur
            cur=third
        return pre

```