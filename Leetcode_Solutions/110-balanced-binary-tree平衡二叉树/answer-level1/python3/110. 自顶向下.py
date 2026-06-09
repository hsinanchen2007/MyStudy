### 啰嗦几句
只能写出自顶向下的方法，等能看懂了自底向上再来补充吧

### 解题思路
定义一个求高度的函数，那么也就是104题。
来循环的判断每一个子树是不是都是balanced。

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

        def __depth(node):
            if not node:
                return 0
            return max(__depth(node.left), __depth(node.right)) + 1
        
        if not root:
            return True

        return abs(__depth(root.left) - __depth(root.right)) < 2 and self.isBalanced(root.left) and self.isBalanced(root.right)

```