### 解题思路
- 层次遍历同时加上当前节点的level即可

### 代码

```python
from typing import List
from collections import deque, defaultdict


# Definition for a binary tree node.
# class TreeNode:
    # def __init__(self, x):
        # self.val = x
        # self.left = None
        # self.right = None


class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = defaultdict(list)
        d = deque()
        d.append((root, 0))
        while d:
            node, level = d.popleft()
            res[level].append(node.val)
            if node.left:
                d.append((node.left, level - 1))
            if node.right:
                d.append((node.right, level + 1))

        return [res[x] for x in sorted(res.keys())]

```