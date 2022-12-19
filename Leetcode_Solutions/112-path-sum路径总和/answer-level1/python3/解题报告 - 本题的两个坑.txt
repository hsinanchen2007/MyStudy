1. 本题的第一个坑：终止条件的判断，当root is None时，该结点不一定是叶子节点，当且仅当root.left is None and root.right is None时，该节点为叶子节点
2. 本题的第二个坑：当root.left is None and root.right is None时，应该判断sum == root.val，而不应该时0 == root.val，因为此时sum还没有减去root.val

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        if root.left is None and root.right is None:
            return sum == root.val
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)
```
