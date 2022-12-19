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
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        new_root = TreeNode(root.val)
        node_list = [root,new_root]
        while node_list:
            node = node_list.pop(0)
            new_node = node_list.pop(0)
            new_node.left  = TreeNode(node.right.val) if node.right else None
            new_node.right = TreeNode(node.left.val) if node.left else None
            if node.left:
                node_list += [node.left, new_node.right]
            if node.right:
                node_list += [node.right, new_node.left]
        return self.dfs(root,new_root)
        
    def dfs(self,node,new_node):
        if not node:
            return True
        if not new_node:
            return False
        return node.val == new_node.val and self.dfs(node.left,new_node.left) and self.dfs(node.right,new_node.right)

```