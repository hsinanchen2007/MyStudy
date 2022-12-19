### 解题思路
递归方法求解：
叶节点的层数返回1
空节点的层数返回0
其他节点的层数返回 max(左子树层数，右子树层数) +11

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        if (not root.left) and (not root.right):
            return 1
        else:
            return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
```