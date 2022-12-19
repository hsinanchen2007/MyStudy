### 解题思路
append操作，偶数行从左到右；奇数行从右到左

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
        if not root: return []
        res = []
        def dfs(node, level):
            if not node:
                return
            # if level == len(res):
            #     res.append([])
            # if level % 2 == 0:
            #     res[level].append(node.val)
            # else:
            #     res[level].insert(0, node.val)
            if level == len(res):
                res.append(deque([]))
            # append操作，偶数行从左到右；奇数行从右到左
            if level % 2 == 0:
                res[level].append(node.val)
            else:
                res[level].appendleft(node.val)
            dfs(node.left, level+1)
            dfs(node.right, level+1)


        dfs(root, 0)
        return res
```