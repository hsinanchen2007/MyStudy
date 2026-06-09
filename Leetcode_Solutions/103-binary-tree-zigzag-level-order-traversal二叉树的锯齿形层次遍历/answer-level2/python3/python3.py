### 解题思路
菜鸟分享一下自己的思路
大佬们多多指教

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
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        awr = []
        if not root:
            return awr

        node_list = deque([root, None])
        level = 0
        while node_list:
            n = len(node_list)
            level_list = deque()
            for i in range(n):
                node = node_list.popleft()
                if node:
                    if level%2==0:
                        level_list.append(node.val)
                    else:
                        level_list.appendleft(node.val)
                    if node.left:
                        node_list.append(node.left)
                    if node.right:
                        node_list.append(node.right)
            level += 1
            awr.append(list(level_list))
        return awr

```