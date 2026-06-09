### 解题思路
如标题

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        return self.dfs(root)

    
    def dfs(self,Node):
        if Node == None:
            return
        left = Node.left
        Node.left = self.dfs(Node.right)
        Node.right = self.dfs(left)
        return Node
```