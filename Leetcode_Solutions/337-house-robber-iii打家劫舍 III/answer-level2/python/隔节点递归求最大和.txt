
### 代码
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def __init__(self):
        self.dic = dict()
    def rob(self, root: TreeNode) -> int:
        if not root:return 0
        if root in self.dic:return self.dic[root]
        temp = root.val
        if root.left: temp += self.rob(root.left.left)+self.rob(root.left.right)
        if root.right: temp += self.rob(root.right.left)+self.rob(root.right.right)
        self.dic[root] = max(temp, self.rob(root.left)+self.rob(root.right))
        return self.dic[root]
```