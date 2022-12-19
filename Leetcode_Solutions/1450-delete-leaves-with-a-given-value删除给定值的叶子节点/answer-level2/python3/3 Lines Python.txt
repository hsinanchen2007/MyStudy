### 解题思路
精神小伙 简单实现

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if not root: return None
        root.left,root.right=self.removeLeafNodes(root.left,target),self.removeLeafNodes(root.right,target)
        return None if root.val==target and not root.left and not root.right else root
```