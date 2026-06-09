### 解题思路
![image.png](https://pic.leetcode-cn.com/013f131e9f102330b19f674b3d267ed4ba1a8630fcaad31f1a41206bcabb6ee0-image.png)
- 思路很常规,直接写代码

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
        max_depth = [0]
        def dfs(root,depth):
            if not root:
                return 
            depth += 1 
            if max_depth[0] < depth:
                max_depth[0] = depth
            dfs(root.right, depth)
            dfs(root.left, depth)
        dfs(root, 0)
        return max_depth[0]


            
            
```