### 解题思路
遍历原来的链表，将链表的当前节点指向上一个节点，头节点指向None,每次更新，先用一个中间变量将原链表中当前节点的下一个节点存储，当前节点指向上一个节点，将当前节点和中间变量分别赋给上一个节点和当前节点，不断更新上一个节点和当前节点，实现链表反转。

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
        if not head:
            return None
        if not head.next:
            return head

        pre_node = None
        node = head
        while (node):
            temp_next = node.next
            node.next = pre_node
            pre_node = node
            node = temp_next
        return pre_node
```