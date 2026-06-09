### 解题思路
递归+记忆

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        # O(lgN)+O(N+H) -> O(lgN)+O(1+H)
        def inorder(root: TreeNode) -> List[int]:
            if not root:return None
            inorder(root.left)
            # exclude first node
            # 0 not for bool! 
            if self.prev_val is not None:self.min_abs = min(self.min_abs,root.val-self.prev_val)
            self.prev_val = root.val
            inorder(root.right)
        self.min_abs = float('inf')
        self.prev_val = None
        inorder(root)
        return self.min_abs

    
```