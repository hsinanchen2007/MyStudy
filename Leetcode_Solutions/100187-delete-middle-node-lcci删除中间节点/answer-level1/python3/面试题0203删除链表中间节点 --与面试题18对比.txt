### 解题思路
与面试题18相同思路，**节点依次前移覆盖之前的节点**

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
        #与面试题18相同思路
        #节点依次前移

        while node.next:#将后面的各节点都前移（自前向后覆盖）
            node.val = node.next.val#val覆盖
            if node.next.next:#next覆盖（依次前移）
                node = node.next
            else: 
                node.next = None


```