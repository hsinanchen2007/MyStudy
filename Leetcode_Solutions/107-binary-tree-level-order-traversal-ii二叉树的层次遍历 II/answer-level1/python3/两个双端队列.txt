### 解题思路
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
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        # 这道题和102有什么区别吗。。。。看不出来，结果直接存一个双端队列里面，每次插入都是O(1)
        # base case:
        res = deque()
        queue = deque()
        if root is None:
            return res
        queue.append(root)
        while queue:
            level = []
            size = len(queue)
            for i in range(size):
                node = queue.popleft()
                level.append(node.val)
                if node.left:queue.append(node.left)
                if node.right:queue.append(node.right)
            res.appendleft(level)
        return res
```