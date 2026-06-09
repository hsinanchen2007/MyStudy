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

from collections import deque

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        # 用字典来储存个depth的结果
        res = {}
        queue = deque()
        queue.append((root, 0))
        while queue:
            head, depth = queue.popleft()
            if head:
                if depth not in res:
                    res[depth] = [head.val]
                else:
                    res[depth].append(head.val)
            if head.left:
                queue.append((head.left, depth+1)) 
            if head.right:
                queue.append((head.right, depth+1))
        return [res[key] for key in res.keys()]
```