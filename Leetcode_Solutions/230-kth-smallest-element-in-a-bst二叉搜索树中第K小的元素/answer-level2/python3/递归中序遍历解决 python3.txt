
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        # 利用中序遍历
        def inorder_traversal(root):
            if not root:
                return []
            return inorder_traversal(root.left) + [root.val] + inorder_traversal(root.right)
        
        
        return inorder_traversal(root)[k-1]
```