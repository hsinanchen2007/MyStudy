### 解题思路
https://twitter.com/mxcl/status/608682016205344768 有趣！

[评论区有个人很搞笑](https://leetcode-cn.com/problems/invert-binary-tree/comments/108673)

[评论区前序，中序，后序，层次序](https://leetcode-cn.com/problems/invert-binary-tree/comments/79745)

此题和我之前没做出来的那题一样，[101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)

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
        if root == None:
            return 
        if root.left:
            self.invertTree(root.left)
        if root.right:
            self.invertTree(root.right)
        root.left, root.right = root.right, root.left
        return root
```