### 解题思路
递归

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root:
            return []
        elif root.left == None and root.right == None:
            return [str(root.val)]
        else:
            res = self.binaryTreePaths(root.left) + self.binaryTreePaths(root.right)
            for i in range(len(res)):
                res[i] = str(root.val) + "->" +res[i]
            return res
```