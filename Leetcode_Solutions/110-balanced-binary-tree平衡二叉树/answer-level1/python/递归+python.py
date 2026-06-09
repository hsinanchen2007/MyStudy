### 解题思路
递归阻断思想，记录一下
1、首先继承后序遍历的思想,先left,后right，再进行基本操作
2、确定返回值，左右子树的高度，max(left,right)+1
3、当abs(left-right)>2，用-1标记
4、*优化*：在每次递归过程中，都有计算左右子树高度，因此只要有标记-1出现，都直接截断返回

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root):
        return self.depth(root) != -1

    def depth(self, root):
        if not root: return 0
        left = self.depth(root.left)
        if left == -1: return -1
        right = self.depth(root.right)
        if right == -1: return -1
        return max(left, right) + 1 if abs(left - right) < 2 else -1

```