### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def isValid(pre: int, current: int):
    return pre < current

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        pre = TreeNode(-float('inf'))
        stack = []
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if not isValid(pre.val, root.val):
                return False
            pre = root
            root = root.right
        return True
            


```

```
# -*- coding: utf-8 -*-
from structure.data import TreeNode

t = TreeNode(2)
t.left = TreeNode(1)
t.right = TreeNode(1)


def isValid(pre: int, current: int):
    return pre < current


class Solution:
    pre = TreeNode(float('-inf'))
    isValid = None

    def iterateValidBST(self, root: TreeNode) -> bool:
        pre = TreeNode(-float('inf'))
        stack = []
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if not isValid(pre.val, root.val):
                return False
            pre = root
            root = root.right
        return True

    def recursiveValid(self, root: TreeNode) -> bool:

        def rec(root: TreeNode):
            if root is None:
                return
            rec(root.left)
            if self.pre.val >= root.val:
                self.isValid = False
            self.pre = root
            rec(root.right)

        rec(root)
        return True

s = Solution()
s.recursiveValid(t)
print(s.isValid)

```