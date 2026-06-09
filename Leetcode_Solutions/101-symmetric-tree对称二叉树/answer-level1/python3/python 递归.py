### 解题思路
参考 100.相同的树 不同点：对称二叉树判断子树相同时，判断条件为 
left == right  right == left 
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
        def isSameTree(p: TreeNode, q: TreeNode) -> bool:
            if p == None and q == None:
                return True
            elif p and q:
                return p.val==q.val and isSameTree(p.left, q.right) and isSameTree(p.right, q.left)
            else:
                return False
        return isSameTree(root,root)
```