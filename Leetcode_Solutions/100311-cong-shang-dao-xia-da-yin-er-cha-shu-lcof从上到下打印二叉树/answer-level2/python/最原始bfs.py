### 解题思路
![image.png](https://pic.leetcode-cn.com/a983567a73af9b8854fc64c8446d17fb2009506b75bfa161bb1f1d932e8ebb0c-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        # bfs
        if not root:
            return []
        stack = [root]
        res = []
        while stack:
            node = stack.pop(0)
            if node:
                stack.extend([node.left, node.right])
                res.append(node.val)
        return res
            

```