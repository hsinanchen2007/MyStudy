### 解题思路
递归解法时，head.next.next = head 表示head的下一节点指向head，然后 head.next = None 将head下一节点置为空，防止出现循环 A->B->A 的结构。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#    def __init__(self, x):
#        self.val = x
#        self.next = None
# 递归
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        tempnode = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return tempnode
```