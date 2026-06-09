### 解题思路
此处撰写解题思路
刚开始按照固定思路，发现无法传值，直接在给定的链表的节点上操作，将当前节点的值替换成当前节点后面的节点值，然后将后面那个节点删除即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val=node.next.val
        node.next=node.next.next
        
```