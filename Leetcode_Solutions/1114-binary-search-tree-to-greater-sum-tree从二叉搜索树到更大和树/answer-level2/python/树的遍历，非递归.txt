## 思路
相当有对树进行右 中 左的遍历方式，直接使用栈来进行处理，中间使用一个变量存储遍历过的节点的和



## 代码


```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.record = 0
        stack = []
        cur = root
        while cur:
            stack.append(cur)
            cur = cur.right
        while len(stack):
            item = stack.pop()
            item.val += self.record
            self.record = item.val
            cur = item.left
            while cur:
                stack.append(cur)
                cur = cur.right
        return root
```
