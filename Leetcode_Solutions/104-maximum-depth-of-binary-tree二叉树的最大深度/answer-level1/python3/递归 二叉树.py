### 解题思路
DFS（深度优先策略）
递归
return语句中 每次递归 数目+1
需要把非递归版本的解法手写一遍

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
        
        left_height = self.maxDepth(root.left)
        right_height = self.maxDepth(root.right)

        return max(left_height,right_height) + 1
        
            
            
```