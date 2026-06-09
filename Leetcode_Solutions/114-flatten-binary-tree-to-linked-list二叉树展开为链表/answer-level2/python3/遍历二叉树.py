### 解题思路
此处撰写解题思路
1.深度优先遍历子树
2.如果存在父节点存在左节点，就把左节点插入到父节点与右节点之间，把父节点的做节点置为None即可

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
        if not root:return None
        def helper(r):
            if not r:return
            helper(r.left)
            helper(r.right)
            if r.left:
                tail = r.left
                while tail and tail.right:
                    tail = tail.right
                tail.right = r.right
                r.right = r.left
                r.left = None
            return
        helper(root)
```