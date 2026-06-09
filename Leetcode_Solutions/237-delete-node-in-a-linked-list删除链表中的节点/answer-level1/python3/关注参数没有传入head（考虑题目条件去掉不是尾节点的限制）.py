### 解题思路
1. 题目没有传入head，所以考虑复制删除节点下一个节点的值
2. jianzhioffer的节点把是尾节点的情况考虑在内
3. 复杂度[(n-1)*0(1) + O(n)]/n = O(1)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        # 要删除的节点不是尾节点
        if node.next:
            node.val = node.next.val
            node.next = node.next.next
        # 链表只有一个节点，删除头（尾）节点（删除的节点是尾节点，同时又与头节点相等，故推出）
        elif head == node:
            head = None
        # 链表有多个节点，删除尾节点
        else:
            while head.next ！= node:
                head = head.next
            head.next = None