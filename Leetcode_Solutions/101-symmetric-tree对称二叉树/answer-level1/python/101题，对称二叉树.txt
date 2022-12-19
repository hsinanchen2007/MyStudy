### 解题思路
思想：迭代递归
对称二叉树，即根节点的左子树和右子树镜像对称，使用递归函数，不断判别左右子树，即可。

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
        def check(node1,node2):
            if not node1 and not node2:
                return True
            elif not node1 or not node2:
                return False
            if node1.val != node2.val:
                return False
            return check(node1.left,node2.right) and check(node1.right,node2.left)
        return check(root,root)
```