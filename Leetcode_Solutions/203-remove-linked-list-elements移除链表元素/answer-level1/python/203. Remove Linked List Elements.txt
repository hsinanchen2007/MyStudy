### 解题思路
给链表创建个node, node.next = head, 方便删除元素

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if head is None:
            return head
        # xx建一个虚拟 => 6 -> 1 -> 6 -> None
        tempNode = ListNode(0)
        tempNode.next = head

        cur = tempNode
        while cur.next is not None:
            if cur.next and cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return tempNode.next
```