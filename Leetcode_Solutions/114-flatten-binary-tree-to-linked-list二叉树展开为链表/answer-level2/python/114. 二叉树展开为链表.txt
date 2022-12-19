### 解题思路
- 如果根节点为None，直接返回；
- 否则对其左子树进行展开操作；
- 然后对其右子树进行展开操作；
- 若无左子树，由于展开操作已将右子树展成符合题意的形式，结束；
- 否则走到左子树的尽头，将右子树挂上去，然后将左子树整体挂到右子树上去，将左子树置为None；

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        self.flatten(root.left)
        self.flatten(root.right)
        if root.left:
            pre = root.left
            while pre.right:
                pre = pre.right
            pre.right = root.right
            root.right = root.left
            root.left = None

```