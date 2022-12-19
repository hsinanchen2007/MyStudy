### 解题思路
中序遍历将频率记录在字典中，最后取出最大值

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode):
        if not root:
            return []
        f = {}

        def FindMid(node: TreeNode, f):
            if node.val in f:
                f[node.val] += 1
            else:
                f[node.val] = 1
            if node.left:
                FindMid(node.left, f)
            if node.right:
                FindMid(node.right, f)

        FindMid(root, f)
        res = []
        maxf = max(f.values())
        for item in f.keys():
            if f[item] == maxf:
                res.append(item)
        return res

```