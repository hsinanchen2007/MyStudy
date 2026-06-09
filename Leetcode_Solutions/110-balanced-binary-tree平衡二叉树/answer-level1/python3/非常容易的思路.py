### 解题思路
可以将题目解析为，该树的所有节点左右子树，最大深度的差不超过1，则为平衡
因此采用递归的手段，对每个节点的子树高度差进行判断


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True
        if abs(self.maxDepth(root.left)-self.maxDepth(root.right)) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)

    def maxDepth(self, root: TreeNode) -> int:
        return 0 if not root else max(self.maxDepth(root.left),self.maxDepth(root.right))+1

```