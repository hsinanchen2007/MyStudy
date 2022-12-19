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
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:

        def get_leaves(root, res):
            if not root:
                return None
            if not root.left and not root.right:
                res.append(root.val)
                return res
            else:
                get_leaves(root.left, res)
                get_leaves(root.right, res)
            return res
        
        res1 = get_leaves(root1, [])
        res2 = get_leaves(root2, [])
        return res1 == res2
```