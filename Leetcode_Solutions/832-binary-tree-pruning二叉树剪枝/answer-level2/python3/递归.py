### 解题思路
![微信截图_20200108085155.png](https://pic.leetcode-cn.com/8bdbd203d2118faad08a119dc5e5bc4bf5f2e9d88ae9eee9639feb9dbafd3cff-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200108085155.png)
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
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if root is None or self.iszero(root):
            return None
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        return root

    def iszero(self, root):
        if root is None:
            return True
        return root.val == 0 and self.iszero(root.left) and self.iszero(root.right)

```