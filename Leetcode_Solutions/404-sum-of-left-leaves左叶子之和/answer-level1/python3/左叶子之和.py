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
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if root is None:
            return 0
        else:
            # 如果根节点的左孩子不为空，并且该左孩子没有孩子（即该左孩子已经是叶子节点），则返回它的值，再对根节点的右孩子做相同操作，叠加的和就是左叶子节点的和
            if root.left is not None and (root.left.left is None) and (root.left.right is None):
                return root.left.val + self.sumOfLeftLeaves(root.right)  # 当前根节点的左孩子没有孩子
            else:
                return self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right) # 对左右孩子递归，直到出现某个节点的左孩子是叶子节点
            

```