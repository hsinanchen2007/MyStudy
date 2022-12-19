```python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def preorderleft(tree, kist):
        if tree:
            kist.append(tree.val)
            preorderleft(tree.left, kist)
            preorderleft(tree.right, kist)
        else:
            kist.append('null')

def preorderright(tree, kist):
        if tree:
            kist.append(tree.val)
            preorderright(tree.right, kist)
            preorderright(tree.left, kist)
        else:
            kist.append('null')

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        k1 = []
        k2 = []
        preorderleft(root, k1)
        preorderright(root, k2)
        if k1 == k2:
            return True
        else:
            return False
```
