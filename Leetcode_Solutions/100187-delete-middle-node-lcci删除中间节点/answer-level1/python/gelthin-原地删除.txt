### 解题思路
同习题 [237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)
没有 prev 指针，如何原地删除，
因为无法改变 prev 的指针，所以当前节点必须保留。

其实只要把下一个节点的值 copy 到这个节点上， 然后删除下一个节点即可。

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
        node.val = node.next.val
        A = node.next
        node.next = node.next.next
        del A
```