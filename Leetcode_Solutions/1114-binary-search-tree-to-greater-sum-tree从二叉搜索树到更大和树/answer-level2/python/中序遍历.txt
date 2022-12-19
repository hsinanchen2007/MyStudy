### 解题思路
中序遍历

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.sums = 0;
        self.DFS(root)
        return root
    
    def DFS(self,root):
        if root.right!=None:
            self.DFS(root.right)
        self.sums += root.val
        root.val = self.sums
        if root.left!=None:
            self.DFS(root.left)

```