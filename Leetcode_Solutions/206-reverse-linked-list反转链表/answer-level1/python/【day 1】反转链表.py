### 解题思路

辅助值来帮助
输入的链表头指针是NULL
输入的链表只有一个结点
输入的链表有多个结点

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
        if head == None or head.next == None:
            return head
        p=head
        left = None
        while p.next:
            q=p.next
            p.next=left
            left=p
            p=q
        p.next =left
        return p

```