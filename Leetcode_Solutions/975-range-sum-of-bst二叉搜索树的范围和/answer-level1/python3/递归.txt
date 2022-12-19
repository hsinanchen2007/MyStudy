### 解题思路
此处撰写解题思路
1.root.val<L ,右子树之和
２.root.val>R,左子树之和
３.L<=root.val<=R,本身+左子树+右子树之和

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:

        if not root:
            return 0
        if root.val < L:
            return self.rangeSumBST(root.right, L, R)
        if root.val > R:
            return self.rangeSumBST(root.left, L, R)

        return root.val + self.rangeSumBST(root.left, L, R) + self.rangeSumBST(root.right, L, R)

```