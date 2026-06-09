### 解题思路
1. 创建一个新链表的起始点 None
2. 原链表节点作为新链表的起始点，之前链表的起始点作为该节点的 Next
3. 顺延原链表的节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 1、
        r_node = None
        while head:
            # 记录原链表的下一个节点，因为后面会改变链表的指向，防止丢失链表的节点位置
            tmp_node = head.next
            
            # 2、
            head.next = r_node
            
            # 3、
            r_node = head
            head = tmp_node
        return r_node

```
