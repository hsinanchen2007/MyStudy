### 解题思路
层次遍历后结果反转即可

### 代码

```

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        res = []

        d = deque()
        d.append(root)
        level = 0
        while(d):
            size = len(d)
            temp = []
            while(size>0):
                node = d.pop()
                temp.append(node.val)
                if node.left:
                    d.appendleft(node.left)
                if node.right:
                    d.appendleft(node.right)
                size-=1
            res.append(temp)
        return res[::-1]

```