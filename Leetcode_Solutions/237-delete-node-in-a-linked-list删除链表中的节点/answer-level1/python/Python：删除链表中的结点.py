### 解题思路
我成功被题目打败了！！！
学习算法第一步，最大的难点和重点——学好语文！
苦思冥想一个链表开头，一个要删除的参数，那么node到底是哪个？另一个在哪里？
最后发现node就是要删除的那个……

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