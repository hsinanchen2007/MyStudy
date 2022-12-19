### 解题思路
没有思路

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

        if not head or not head.next:
            return head
        
        dummy = ListNode(0)
        dummy.next = head
        pre_node, cur_node, next_node = head, head.next, head.next.next
        pre_node.next = None
        while cur_node:
            cur_node.next = pre_node
            pre_node = cur_node
            if next_node:
                cur_node = next_node
                next_node = next_node.next
            else:
                cur_node = None
        return pre_node
```