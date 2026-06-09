### 解题思路
递归

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        return self.helper(root1) == self.helper(root2)
    
    #返回root为根节点的树的叶值序列
    def helper(self,root):
        if not root:
            return []
        elif root.left == None and root.right == None:
            return [root.val]
        else:
            return self.helper(root.left) + self.helper(root.right)
```