### 解题思路
增加辅助层数参数。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        levels = []
        if root == None:
            return levels
        
        def helper(root, level):
            if len(levels) < level:
                levels.append([])
            levels[level - 1].append(root.val)
            if root.left:
                helper(root.left,level+1)
            if root.right:
                helper(root.right,level+1)
                
        helper(root,1)
        return levels
```