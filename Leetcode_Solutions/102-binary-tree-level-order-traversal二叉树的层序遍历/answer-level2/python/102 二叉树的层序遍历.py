### 解题思路
广度优先搜索

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels

        def bfs(root, level):
            if len(levels) == level:
                levels.append([])

            levels[level].append(root.val)

            if root.left:
                bfs(root.left, level+1)
            if root.right:
                bfs(root.right, level+1)
            

        bfs(root, 0)
        return levels
```