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
    def sumNumbers(self, root: TreeNode) -> int:
        def dfs(path: List[str], root: TreeNode, res: List[List[str]]):
            if not root:
                return
            if not root.left and not root.right:
                path += (str(root.val))
                res.append(path)
                return

            dfs(path + str(root.val), root.left, res)
            dfs(path + str(root.val), root.right, res)

        res = []
        dfs('', root, res)
        sumnum = 0
        for i in res:
            sumnum += int(i)
        return sumnum
```