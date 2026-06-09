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
        self.num =0
    def convertBST(self, root: TreeNode) -> TreeNode:

        def dfs_bst(root:TreeNode):
            if not root:
                return
            dfs_bst(root.right)
            

            self.num+=root.val
            root.val = self.num
            dfs_bst(root.left)


        dfs_bst(root)
        return root
        
        
```