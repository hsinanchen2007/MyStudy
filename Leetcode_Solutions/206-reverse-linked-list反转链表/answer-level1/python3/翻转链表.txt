### 解题思路
简易方法，新建一个链表作为返回链表。
讲原始链表的节点，一次插入到返回链表的头节点。
即为返回链表。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        return_node = None
        while head:
            local = head
            head = head.next
            local.next = return_node
            return_node = local
        return return_node


```