### 解题思路
DFS（深度优先搜索）策略的示例

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        if not root:
            return 0
        else:
            maxleft = self.maxDepth(root.left)
            maxright = self.maxDepth(root.right)
            return max(maxleft, maxright) + 1
```