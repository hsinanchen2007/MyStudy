### 解题思路
队列广度遍历

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
        if not root:
            return []
        que = []
        que.append(root)
        res = []
        while que:
            p = que.pop(0)
            res.append(p.val)
            if p.left:
                que.append(p.left)
            if p.right:
                que.append(p.right)
        return res
```