### 解题思路
看代码就可以看明白，代码很简单

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
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
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
            if level%2!=0:
                res.append(temp[::-1])
            else:
                res.append(temp)
            level+=1
        return res



```