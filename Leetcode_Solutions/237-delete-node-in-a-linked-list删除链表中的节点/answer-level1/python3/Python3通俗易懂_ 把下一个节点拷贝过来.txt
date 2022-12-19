### 解题思路
直接把下一个节点的属性复制到当前node节点位置. 这相当于删掉了下一个节点, 且用它的值替换了当前节点. 那不就是相当于删除了当前node节点吗

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
        p = node
        after = p.next  # make p like its after
        p.val = after.val
        p.next = after.next
        
             
```