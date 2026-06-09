### 解题思路
利用二叉搜索树的性质解题：左子节点的值<根节点的值<右子节点的值
从root节点开始逐层往下遍历，直到找到符合要求的节点

时间复杂度：O(h)
空间复杂度：O(1)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root:
            if p.val < root.val and q.val < root.val:
                root = root.left
            elif p.val > root.val and q.val > root.val:
                root = root.right
            else:
                return root
```