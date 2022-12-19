### 解题思路
和前序思路类似，不过要先右后左（root -> right -> left），最后翻转列表即为后序

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        out = []
        if not root: return out
        stack = [root]
        while stack:
            node = stack.pop()
            out.append(node.val) 
            if node.left: stack.append(node.left)
            if node.right: stack.append(node.right)  
        out.reverse()
        return out
```