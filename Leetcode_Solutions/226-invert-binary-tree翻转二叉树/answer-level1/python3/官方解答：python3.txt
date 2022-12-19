### 解题思路
思路：翻转二叉树其实就是我们熟悉的交换二叉树操作，用先序遍历交换。
      先序遍历这棵树的每个节点，如果遍历到节点有子节点就交换它的两个子节点，
      交换完所有非叶子节点的左右节点之后，就得到了答案。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return
        root.left,root.right=root.right,root.left
        if root.left:
            self.invertTree(root.left)
        if root.right:
            self.invertTree(root.right)
        return root
```