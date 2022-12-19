![图片.png](https://pic.leetcode-cn.com/7965038a57ef169f4591775deb261f8c52c0b28f61d5e5511e527ce34317c678-%E5%9B%BE%E7%89%87.png)

双端队列 + 标志位
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return res
        q = deque()
        q.append((0, root))
        flag = True
        prev_cl = 0
        while q:
            cl, cr = q[0][0], q[-1][0]
            if cl == cr and cl != prev_cl:
                flag = not flag
                prev_cl = cl
            if flag:
                level, node = q.popleft()
                if not node:
                    continue
                q.append((level+1, node.left))
                q.append((level+1, node.right))
            else:
                level, node = q.pop()
                if not node:
                    continue
                q.appendleft((level+1, node.right))
                q.appendleft((level+1, node.left))
            if len(res)==level:
                res.append([])
            res[level].append(node.val)
        return res
        
```