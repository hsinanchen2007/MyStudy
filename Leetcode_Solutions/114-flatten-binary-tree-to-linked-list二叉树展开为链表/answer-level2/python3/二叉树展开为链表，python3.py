### 解题思路
如果当前节点root没有左孩子
`root = root.right`
否则，我们寻找左孩子最右边的节点left
把root的右孩子接到left的右边
`left.right = root.right`
把root的左孩子接到右边
`root.right = root.left`
把root的左孩子置空
`root.left = None`

一直循环下去，直到root为空


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
        while root:
            if not root.left:
                root = root.right
            else:
                left = root.left
                while left.right:
                    left = left.right
                left.right = root.right
                root.right = root.left
                root.left = None
```