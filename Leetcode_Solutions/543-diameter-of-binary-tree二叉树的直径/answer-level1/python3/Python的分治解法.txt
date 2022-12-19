### 解题思路
本题有一个最大的坑，就是路径可能穿过根结点也可能不穿过根结点，所以分治思想是最自然最清晰的。对根结点的处理和对子结点的处理并无二致。

对每一个结点而言，将此结点做为根结点的直径就是左右子树的深度之和。子结点需要向父结点传递的信息有两个，一个是当前子树的深度来给父结点计算直径，一个是当前子树里的最大直径来给父结点做比较，打擂台看谁最大并继续向更上层的父结点传递最大直径。

题目不要求返回最大直径的结点，所以只返回最大直径就好了。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root is None:
            return 0

        rootDepth, maxPath = self.helper(root)
        return maxPath

    def helper(self, root):
        if root is None:
            return 0, 0
        
        leftDepth, leftMaxPath = self.helper(root.left)
        rightDepth, rightMaxPath = self.helper(root.right)

        rootDepth = max(leftDepth, rightDepth) + 1
        rootPath = leftDepth + rightDepth

        return rootDepth, max(rootPath, leftMaxPath, rightMaxPath)

```