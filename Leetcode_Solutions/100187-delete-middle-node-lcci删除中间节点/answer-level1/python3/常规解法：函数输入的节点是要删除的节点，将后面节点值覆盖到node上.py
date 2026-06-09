### 解题思路
```python3
node.val=node.next.val # 覆盖
node.next=node.next.next # 连接
```


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
        node.val,node.next=node.next.val,node.next.next
```