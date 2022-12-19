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

class Solution:
    def __init__(self):
        self.node =[]
    def kthSmallest(self, root: TreeNode, k: int) -> int:

        def dfs_tree(root:TreeNode,k:int):
        
            if root.left:
                dfs_tree(root.left,k)
            if root:
                self.node.append(root.val)
            if root.right:
                dfs_tree(root.right,k)

        dfs_tree(root,k)
        return self.node[k-1]
        
```