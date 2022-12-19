> 11.26 python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # 迭代
    def preorderTraversal(self, root):
        self.result = []
        stack = []
        tmp = root
        while tmp or stack:
            while tmp:
                self.result.append(tmp.val)
                stack.insert(0, tmp)
                tmp = tmp.left
            top = stack.pop(0)
            tmp = top.right

        return self.result
    # 递归
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        self.result = []
        def dfs(root):
            if root:
                self.result.append(root.val)
                dfs(root.left)
                dfs(root.right)
        dfs(root)
        return self.result

```