### 解题思路
首先判断两个树是否都为 None，都为 None，返回 True。
如果不为 None，左右子树递归遍历 判断 val值是否相等，若相等，则返回 True。
否则，返回 False。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None:
            return True
        elif p and q:
            return p.val==q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        else:
            return False
```